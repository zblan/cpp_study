#include <iostream>
#include <cassert>
class T{
public:
	T(int i = 0) : data(i){std::cout<< "T ¹¹Ôì\n";}
	~T(){std::cout<< "TÎ÷¹µ\n";}
	void show()const { std::cout << data << std::endl;} 
private:
	int data;
};

class SmartPointer{
public:
	SmartPointer(T* p = nullptr):ptr(p){}
	~SmartPointer(){delete ptr;}
	T& operator*(){
		assert(ptr);
		return *ptr;
	}
	T* operator->(){
		assert(ptr);
		return ptr;
	}
	operator bool()const {
		return ptr != nullptr;
	}
private:
	T * ptr;
};
int main(){
	T* p1 = new T(2);
	(*p1).show();
	p1->show();
	if(p1) std::cout << "p1 ok\n";
	delete p1;
	SmartPointer pd(new T(1));
	(*pd).show();
	pd->show();
	if(pd) std::cout << "pd ok\n";
	return 0;
}
