#include <iostream>
#include <string>
#include <vector>
#include <memory>
int main(){
	std::allocator<std::string> alloc;
	std::string* const p = alloc.allocate(10);
	std::string* q = p;
	alloc.construct(q++);
	alloc.construct(q++,5,'A');
	alloc.construct(q++,"abc");
	while(q != p){
		alloc.destroy(--q);
	}
	alloc.deallocate(p, 10);
	std::vector<std::string> vec = {"abc","xyz","c++","python"};
	std::string* const p1 = alloc.allocate(vec.size()+3);
	std::string* q1 = uninitialized_copy(vec.begin(), vec.end(), p1);
	//uninitialized_fill_n(q1, 3, "hello");
	std::string *q2 = p1;
	while(q2 != q1){
		std::cout << *q2++ << "\t";
	}
	return 0;
}
