#include <iostream>
#include <string>
class Person{
public:
	void eat(const std::string& food){
		std::cout << "i eat:" << food << std::endl;
	}
	void sleep(const std::string& place ){
		std::cout << "i sleep:" << place << std::endl;
	}
private:
	std::string name;
	int age;
};
class Student :public Person{
public:
	void study(const std::string course){
		std::cout << "i study:" << course << std::endl;	
	}
};
class Teacher :public Person{
public:
	void teach(const std::string course){
		std::cout << "i teach:" << course << std::endl;
	}
};
//int main(){
//	Student stu;
//	stu.eat("¿¾Ñ¼");
//	stu.study("c++");
//	Teacher teacher;
//	teacher.eat("gutou");
//	teacher.teach("c++");
//	return 0;
//}
