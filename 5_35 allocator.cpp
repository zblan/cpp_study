#include <iostream>
#include <string>
#include <utility>
int main(){
	std::string *ps = new std::string[100];
	std::string s;
	std::string *q = ps;
	std::cout <<  "test";
	while(std::cin >> s && s != "quit" && q != ps + 100){
		*q++ = std::move(s);
		std::cout << *q;
	}
	std::cout << *q;
	delete[] ps;
	return 0;
}

