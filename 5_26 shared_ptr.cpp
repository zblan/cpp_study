#include <iostream>
#include <memory>
using std::weak_ptr;
using std::shared_ptr;
using std::make_shared;
int main(){
	std::weak_ptr<int> wp1;
	
	std::shared_ptr<int> sp1 = make_shared<int>(100);
	//std::shared_ptr<int> sp3 = sp1;
	std::cout << sp1.use_count() << std::endl;
	wp1 = sp1;
	std::cout << sp1.use_count() << std::endl;
	weak_ptr<int> wp2(sp1);
	std::cout << wp2.use_count() << std::endl;
	if(!wp2.expired()){
		shared_ptr<int> sp2 = wp2.lock();
		if(sp2) std::cout << "×ª»»³É¹¦\n"; 
	}
	std::cout << sp1.unique() << std::endl;
	return 0; 
}
