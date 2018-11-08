#include <iostream>
#include <string>
class Base{
public:
	Base(int i){
		std::cout << "Base构造函数" << i << std::endl;
	}
	~Base(){
		std::cout << "Base:析构" << std::endl; 
	}
};
class D1:public Base{
public: 
	D1(int i):Base(i) { std::cout << "D1:默认构造" << std::endl; }
	~D1() { std::cout << "D1:析构" << std::endl; }
}; 
class D2 :public D1 {
public:
	D2(int i) : D1(i){ std::cout << "D2:默认构造" << std::endl; }
	~D2() { std::cout << "D2:析构" << std::endl; }
};
//int main(){
//	D2 d2(1);
//	std::cout << "---------" << std::endl;
//	return 0;
//}
