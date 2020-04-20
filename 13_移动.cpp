#include <iostream> 
#include <string>
class Base{
public:
	Base(int _b):b(_b), pb(new int(_b)){ std::cout<<"Base ����"<< std::endl;}
	~Base(){
		std::cout << "base����"<<std::endl;
		delete pb;
	}
	Base(Base&& other):b(other.b), pb(other.pb){
		other.pb = NULL;
		std::cout << "Base �ƶ�����" << std::endl;
	}
	Base& operator=(Base&& other){
		if(this != &other){
			b = other.b;
			pb = other.pb;
			other.pb = NULL;
		}
		std::cout<< "Base�ƶ����������" << std::endl;
		return *this; 
	}
	int b;
	int *pb;
};
class D1: public Base{
public:
	D1(int _b, int _d):Base(_b),d(_d),pd(new int(_d)){
		
	}
	~D1(){
		std::cout<<"D1������"<<std::endl;
		delete pd; 
	}
	D1(D1&& other):Base(std::move(other)),d(other.d),pd(other.pd){
		other.pd = NULL;
		std::cout<<"D1�ƶ�����"<<std::endl;
	}
	D1& operator=(D1&& other){
		Base::operator=(std::move(other));
		if(this != &other){
			d = other.d;
			pd = other.pd;
			other.pd = NULL;//��֤�ƺ�Դ���������
		}
		std::cout<<"D1�ƶ���ֵ���������"<<std::endl; 
		return *this;
	}
	int d;
	int *pd;
};
//int main(){
//	D1 d1(1, 2);
//	std::cout << "--------------------------------"<<std::endl;
//	//D1 d2(d1); //���������ƶ����죬�����Լ����忽������
//	D1 d2(std::move(d1)); //�ƶ�����
//	std::cout << d2.b << " " << d2.d << std::endl;
//	std::cout << d1.pb << " " << d1.pd << std::endl; // NULL
//	std::cout << d2.pb << " " << d2.pd << std::endl;
//	D1 d3(0, 0);
//	//d3 = d2; //���������ƶ����죬�����Լ����忽����ֵ��������
//	d3 = std::move(d2);
//	std::cout << d3.b << " " << d3.d << std::endl;
//	std::cout << d2.pb << " " << d2.pd << std::endl;
//	std::cout << d3.pb << " " << d3.pd << std::endl;
//	return 0;
//} 
