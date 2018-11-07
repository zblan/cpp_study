#include <memory>
#include <iostream>
#include <mutex>
#include <thread>
class Image{
public:
	Image(int i):image(i){
		if (i % 4 == 1) throw "Cr_Img error";
		//1,5,9...Å×Òì³£
	}
private:
	int image;
};
class ImageMenu{
public:
	ImageMenu(int i=0):image(new Image(i)),change_size(0){	}
	~ImageMenu(){
		delete image;
	}
	void set_image(int img);
private:
	Image *image;
	int change_size;
	std::mutex mtx;
};
void ImageMenu::set_image(int img){
	mtx.lock();
	delete image;
	image = nullptr;
	change_size++;
	image = new Image(img);
	std::cout<< change_size << std::endl;
	mtx.unlock();
}
ImageMenu img_menu;
void do_thread(int image){
	try {
		img_menu.set_image(image);
	}
	catch (const char * e) {
		std::cout << e << std::endl;
	}
}
int main(){
	std::thread threads[8];
	for(int i = 0; i < 8; i++){
		threads[i] = std::thread(do_thread, i);
	}
	for(auto &th : threads){
		th.join();
	}
	return 0;
}












