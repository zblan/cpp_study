#include <iostream>
#include <string>
class Cpu{
public:
	virtual void work() = 0;
	virtual ~Cpu(){}
};
class Mem{
public:
	virtual void work() = 0;
	virtual ~Mem(){}
};
class Hdisk{
public:
	virtual void work() = 0;
	virtual ~Hdisk(){}
};
class IntellCpu:public Cpu{
public:
	virtual void work() override{
		std::cout << "intel cpu work";
	}
};
class SamsungMem:public Mem{
public:
	virtual void work() override{
		std::cout << "SamsungMem mem work";
	}
};
class WDHDisk:public Hdisk{
public:
	virtual void work() override{
		std::cout << "WDHDisk mem work";
	}
};
class Computer{
public:
	Computer(Cpu &pcpu,Mem &pmem,Hdisk &phdisk):cpu(&pcpu),mem(&pmem),hdisk(&phdisk){	}
	void work(){
		cpu->work();
		mem->work();
		hdisk->work();
	}
private:
	//抽象类不能实例化  只能使用指针，不能使用Cpu cpu 
	Cpu *cpu;
	Mem *mem;
	Hdisk *hdisk;
};
//int main(){
//	IntellCpu cpu;
//	SamsungMem mem;
//	WDHDisk hdisk;
//	Computer com(cpu,mem,hdisk);
//	com.work();
//}




