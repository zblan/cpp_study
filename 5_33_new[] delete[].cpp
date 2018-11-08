#include <iostream>
#include <cstdlib>
class A{
public:
	A(int i = 0):pi(new int(i)){
		std::cout << "A¹¹Ôì\n";
	}
	~A(){
		std::cout << "AÎö¹¹\n";
		delete pi;
	} 
	/*static*/void* operator new[](std::size_t size){
		if(void * p = malloc(size)){
			std::cout << "-A operator new[]\n";
			return p;
		}
		throw std::bad_alloc();
	}
	/*static*/ void operator delete[](void* p){
		std::cout << "A operator delete[]\n";
		free(p);
	}
private:
	int* pi;
};
int main(){
	A *pa = new A[3];
	std::cout << "------\n";
	delete[] pa;
	return 0;
}
