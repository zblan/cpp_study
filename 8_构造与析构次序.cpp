#include <iostream>
#include <string>
class Base{
public:
	Base(int i){
		std::cout << "Base���캯��" << i << std::endl;
	}
	~Base(){
		std::cout << "Base:����" << std::endl; 
	}
};
class D1:public Base{
public: 
	D1(int i):Base(i) { std::cout << "D1:Ĭ�Ϲ���" << std::endl; }
	~D1() { std::cout << "D1:����" << std::endl; }
}; 
class D2 :public D1 {
public:
	D2(int i) : D1(i){ std::cout << "D2:Ĭ�Ϲ���" << std::endl; }
	~D2() { std::cout << "D2:����" << std::endl; }
};
//int main(){
//	D2 d2(1);
//	std::cout << "---------" << std::endl;
//	return 0;
//}
