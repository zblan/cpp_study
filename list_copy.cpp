#include <iostream> 
#include <cstring>
#include <cassert>
#include <typeinfo>
class Obj{
public:
	virtual ~Obj() = default;
	virtual void print()const = 0;
}; 
class StuObj:public Obj{
public:
	StuObj(int _id,const std::string &_name):id(_id),name(_name){	}
	~StuObj() throw(){}
	virtual void print()const override{
		std::cout << id << ":" << name << "->" << std::endl;
	}
private:
	int id;
	std::string name;
};
class StrObj:public Obj{
public:
	StrObj(const char *str=nullptr){
		if(!str){
			data = new char[1]{'\0'};
		}else{
			data = new char[strlen(str)+1];
			strcpy(data, str);
		}
	}
	~StrObj() throw(){delete data;}
	virtual void print()const override{
		std::cout<<data<<"->" << std::endl;
	}
private:
	char *data;
};
class IntObj:public Obj{
public:
	IntObj(int _data):data(_data){} 
	~IntObj() throw(){	}
	virtual void print()const override{
		std::cout << data << "->" << std::endl;
	} 
private:
	int data;
};
class List;
class Node{
	friend List;
public:
	Node(Obj *data = nullptr):p_data(data),next(nullptr){	}
	~Node(){
		delete p_data;
	}
private:
	Node *next;
	Obj *p_data;
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
	List(const List &other):List(){
		Node * p = other.head;
		Obj * p_new_obj = nullptr;
		while(p){
			if(typeid(*(p->p_data)) == typeid(IntObj)){
				IntObj * p_int = dynamic_cast<IntObj*>(p->p_data);
				p_new_obj = new IntObj(*p_int);
			}
			else if(typeid(*(p->p_data))==typeid(StrObj)){
				StrObj * p_str = dynamic_cast<StrObj*>(p->p_data);
				p_new_obj = new StrObj(*p_str);
			}else if(typeid(*(p->p_data))== typeid(StuObj)){
				StuObj * p_stu = dynamic_cast<StuObj*>(p->p_data);
				p_new_obj = new StuObj(*p_stu); 
			}
			push_back(p_new_obj);
			p = p->next;
		}
		size = other.size;
	}
	void push_back(Obj *p_obj){
		Node *p_new_node = new Node(p_obj);
		if(!head){
			head = p_new_node;
		}else{
			tail->next = p_new_node;
		}
		tail = p_new_node;
		size++;
	}
	void print_list()const{
		Node *p = head;
		while(p){
			p->p_data->print();
			p = p->next;
		}
		std::cout << "NULL\n";
	}
private:
	Node *head;
	Node *tail;
	int size;
};
int main() {
	List L;
	L.push_back(new IntObj(10));
	L.push_back(new StuObj(1001, "ÕÅÈý"));
	L.push_back(new StrObj("abc"));
	L.print_list();
	List L1(L);
	L1.print_list();
	return 0;
}












