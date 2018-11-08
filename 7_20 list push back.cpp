#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
class Obj{
public:
	virtual ~Obj() = default;
	virtual void print()const = 0;
};
class IntObj:public Obj{
public:
	IntObj(int i):data(i){	}
	~IntObj(){	}
	virtual void print()const override{
		std::cout << data << "->" << std::endl;
	}
private:
	int data;
};
class StrObj : public Obj{
public:
	StrObj(const char *str=nullptr){
		if(!str){
			data = new char[1]{'\0'};
		}else{
			data = new char[strlen(str)+1];
			strcpy(data,str);
		}
	}
	~StrObj(){delete data;}
	virtual void print()const override{
		std::cout << "\""<<data << "\" -> " << std::endl;
	}
private:
	char *data;
};
class StuObj : public Obj{
public:
	StuObj(int _id, const std::string &_name):id(_id),name(_name){	}
	~StuObj(){}
	virtual void print()const override {
		std::cout << id << ":" << name << " -> " << std::endl;
	}
private:
	int id;
	std::string name;
};

class List;
class Node{
	friend List;
public:
	Node(Obj *p_obj=nullptr):p_data(p_obj),next(nullptr){	}
	~Node(){ delete p_data;}
private:
	Obj *p_data;
	Node *next;
};
class List{
public:
	List():head(nullptr),tail(nullptr),size(0){	}
	~List(){	
		Node *p = head;
		while(p){
			Node *temp = p->next;
			delete p;
			p = temp;			
		}
		head = tail = nullptr;
	}
	void push_back(Obj *p_obj){
		assert(p_obj);
		Node *node = new Node(p_obj);
		if(!head){
			head = node;
		}else{
			tail->next = node;
		}
		tail = node;
		size++;
	}
	void print_list()const {
		Node *p = head;
		while(p){
			p->p_data->print();
			p = p->next;
		} 
		std::cout << "NULL\n" << std::endl;
	} 
private:
	Node *head;
	Node *tail;
	int size;
};
//int main() {
//	List L;
//	L.push_back(new IntObj(10));
//	L.push_back(new StuObj(1001, "张三"));
//	L.push_back(new IntObj(2));
//	L.push_back(new StrObj("abc"));
//	L.push_back(new IntObj(5));
//	L.push_back(new StuObj(1002, "李四"));
//	L.push_back(new IntObj(4));
//	L.push_back(new StrObj("123ok"));
//	L.push_back(new IntObj(8));
//	L.print_list();
//	return 0;
//}













