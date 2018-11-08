#include <iostream>
#include <string>
class Person {
public:
	void eat(const std::string& food){
		std::cout << "i eat:" << food << std::endl;
	}
	void sleep(const std::string& place ){
		std::cout << "i sleep:" << place << std::endl;
	}
	std::string name;
	int age;
};
class Xiaozhang :public Person{
public:
	void duiren(const std::string course){
		std::cout << "i dui:" << course << std::endl;
	}
	double a;
};
class Teacher :public Xiaozhang{
public:
	void teach(const std::string course){
		std::cout << "i teach:" << course << std::endl;
	}
	int ti;
};
//int main(){
//	Person b;
//	Xiaozhang x;
//	Teacher teacher;
//	std::cout<< "b size:" << sizeof(b) << "x size:" << sizeof(x) << "teacher size:" << sizeof(teacher) << std::endl;
//	teacher.teach("c++");
//	teacher.eat("gutou");
//	return 0;
//}
