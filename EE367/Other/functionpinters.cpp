#include<iostream>

void foo(){
	std::cout<<"Hello foo"<<std::endl;
}

int main(){
	void (*fooptr)() = foo;

	std::cout<<"Hello world"<<std::endl;
	fooptr();
	
	return 0;

}
