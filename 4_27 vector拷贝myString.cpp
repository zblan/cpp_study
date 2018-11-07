#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
class myString{
public:
	myString(const char *str = nullptr);
	myString(const myString& other);
	myString& operator=(const myString& other);
	~myString(){
		if(ps){
			std::cout<< " --Destructor" << std::endl;
		}else{
			std::cout << "ps is NULL" << " --Destructor" << std::endl;
		}
		delete[] ps;
	}
	const char* c_str()const { return ps;}
private:
	char* ps;
};
myString::myString(const char* str){
	if(str == nullptr){
		ps = new char[1]{ '\0'};
		std::cout << ps << " --Default constructor" << std::endl;
	}else{
		int length = strlen(str);
		ps = new char[length+1];
		strcpy)(ps,str);
		std::cout << ps << " --Str constructor" << std::endl;
	}
}
myString::myString(const myString& other){
	int length = strlen(other.ps);
	ps = new char[length+1];
	strcpy(ps, other.ps);
	std::cout << ps << " --Copy constructor" << std::endl;
}

myString& myString::operator=(const myString& other){
	if(this != &other){
		delete[] ps;
		int length = strlen(other.ps);
		ps = new char[length+1];
		strcpy(ps, other.ps);
	}
	std::cout << ps << " --Copy assignment" << std::endl;
	return *this;
}
myString operator+(const myString& a, const myString &b){
	int length = strlen
	
	
	
}

















