#include <iostream>
class Base{
public:
	Base(){
		std::cout << "Base默认构造" << std::endl; 
	};
	Base(int _b):b(_b),pb(&_b){
		std::cout<<"Base构造" << std::endl;
	}
	Base(const Base &other):b(other.b),pb(other.pb){
		std::cout << "Base拷贝构造" << std::endl; 
	}
	Base& operator=(const Base& other){
		if(this != &other){
			b = other.b;
			pb = other.pb;
		}
		std::cout << "Base赋值运算符重载" << std::endl;
		return *this;
	}
	int b;
	int *pb;
}; 
class D1:public Base{
public:
	D1(int _b, int _d):Base(_b),d(_d),pd(&_d){
		
	}
	D1(const D1& other):Base(other),d(other.d),pd(other.pd){
		std::cout << "D1拷贝构造" << std::endl; 
	}
	D1 &operator=(const D1& other){
		Base::operator=(other);
		if(this != &other){
			d = other.d;
			pd = other.pd;
		}
		std::cout << "D1赋值运算符重载" << std::endl;
		return *this;
	}
	int d;
	int *pd;
};
//int main(){
//	D1 d1(1, 2);
//	D1 d2(d1);
//	std::cout << d2.b << " " << d2.d << std::endl;
//	std::cout << d1.pb << " " << d1.pd << std::endl;
//	std::cout << d2.pb << " " << d2.pd << std::endl;
//	std::cout << "-------------------"<< std::endl;
//	D1 d3(0, 0);
//	d3 = d2;   //赋值运算符 d2 --> d3
//	std::cout << d3.b << " " << d3.d << std::endl;
//	std::cout << d2.pb << " " << d2.pd << std::endl;
//	std::cout << d3.pb << " " << d3.pd << std::endl;
//	return 0;
//}







