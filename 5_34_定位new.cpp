#include <iostream>
class A{
public:
	A(int i = 0):pi(new int(i)){
		std::cout << "A¹¹Ôì\n";
	}
	~A(){
		std::cout << "AÎö¹¹\n";
		delete pi;
	}
	void show()const {
		std::cout<< *pi << std::endl; 
	}
private:
	int* pi;
};
char g_buf[200];
int main(){
	void* pbuf = malloc(100);
	A *pa1 = new(pbuf) A(1);
	pa1->show();
	std::cout << pbuf << std::endl;
	std::cout << pa1 << std::endl;
	pa1->~A();
	free(pbuf);
	std::cout << "-------------------" << std::endl;
	char buf[200];
	A* pa2 = new(buf) A(2);
	pa2->show();
	std::cout << (void*)buf << std::endl;
	std::cout << pa2 << std::endl;
	pa2->~A();
	std::cout << "-------------------\n";
	A* pa3 = new(g_buf) A(3);
	pa3->show();
	std::cout << (void*)g_buf << std::endl;
	std::cout << pa3 << std::endl;
	pa3->~A(); 
	return 0;
}
