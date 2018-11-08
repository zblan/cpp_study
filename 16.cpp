#include <iostream>
class A{
public:
	A(int n=0):num(n){
		std::cout<<"+++++++"<<std::endl;
	}
	A(const A& other):num(other.num){
		std::cout<<"-------------"<<std::endl;
	}
private:
	int num;
};
int main(){
	A a;
	A a1(a);
	A a2 = a;
	A a3 = 10;
}
