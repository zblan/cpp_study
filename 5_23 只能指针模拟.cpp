#include <iostream>
class T{
public:
	T(int _data):data(_data){ std::cout << "T����\n" << std::endl;}
	~T(){ std::cout<< "T����\n" << std::endl;}
private:
	int data;
}; 
class SmartPointer{
public:
	SmartPointer(T* p = nullptr) :ptr(p) { std::cout << "SmartPointer gouzao\n"; }
	SmartPointer(const SmartPointer& other):ptr(other.ptr){
		std::cout << "smartpointer ��������\n"; 
	}
	SmartPointer(const SmartPointer&& other):ptr(other.ptr){
		std::cout << "SmartPointer �ƶ�����\n";
	}
	~SmartPointer() { 
		std::cout << "SmartPointer xigou\n";
		delete ptr; 
	}
private:
	T * ptr;
};
int main(){
	T* pt1 = new T(1);
	SmartPointer stp1(pt1);
	T* pt2 = new T(2);
	SmartPointer spt2 = pt2;
	SmartPointer spt3 = std::move(stp1);
	std::cout << "-----------\n";
	return 0;
}
