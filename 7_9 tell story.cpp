#include <iostream>
#include <string>
class Ireader{
public:
	virtual std::string getContent()const = 0;
};
class Book:public Ireader{
public:
	virtual std::string getContent()const override{
		return "Book getContent";
	}
};
class NewsPaper:public Ireader{
public:
	virtual std::string getContent()const override{
		return "News Paper getContent";
	}
}; 
class Mom{
public:
	void tellStory(const Ireader& reader){
		std::cout << reader.getContent() << std::endl;
	}
};
//int main(){
//	Mom mom;
//	Book book;
//	NewsPaper newspaper;
//	mom.tellStory(book);
//	mom.tellStory(newspaper);
//	return 0;
//}






