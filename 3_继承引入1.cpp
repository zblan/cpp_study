#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Student{
public:
	void eat(const std::string& food){
		std::cout<< "�ҳ�:" << food << std::endl; 
	}
	void sleep(const std::string& place){
		std::cout << "��˯��:" << place << std::endl;
	}
	void study(const std::string& course){
		std::cout << "��ѧ��" << course << std::endl;
	}
private:
	std::string name;
	int age;
};
class Teacher{
public:
	void eat(const std::string& food){
		std::cout<< "�ҳ�:" << food << std::endl; 
	}
	void sleep(const std::string& place){
		std::cout << "��˯��:" << place << std::endl;
	}
	void teach(const std::string& course){
		std::cout << "�ҽ̣�" << course << std::endl;
	}
private:
	std::string name;
	int age;
};
int main(int argc, char** argv) {
	Student stu;
	stu.eat("��Ѽ"); 
	stu.study("c++");
	Teacher teacher;
	teacher.eat("duck");
	teacher.teach("c++");
	return 0;
}
