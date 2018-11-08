//Ïà¼Ó
//´òÓ¡
#include <iostream>
class Point{
public:
	Point(int _x, int _y):x(_x), y(_y){	}
	
	int get_x()const{
		return x;
	}
	int get_y()const{
		return y;
	}
	void print()const{
		std::cout<<x<<","<<y<<std::endl;
	}
	Point operator+(const Point &a){
		Point temp(a.get_x()+x, a.get_y()+y);
		return temp;
	}
private:
	int x;
	int y;
}; 
Point operator+(const Point &a, const Point &b){
	Point temp(a.get_x()+b.get_x(), a.get_y()+b.get_y());
	return temp;
}
//int main(){
//	Point p1(10, 20), p2(20, 302);
//	Point p3 = p1 + p2; 
//	p3.print();
//	Point p4 = p1.operator+(p2);
//	p4.print();
//	return 0;
//}
