#include <iostream>
#define LOG(x) std::cout << x << std::endl;

// heap pointer of size double
double *heap_ptr; // this is just a nullptr as defined


int main(){

	{
	// specify a specific block of memory of size double (8 bytes)
	heap_ptr = new double;

	}

	// dereference to store a piece of data in the allocated memory of size double 
	*heap_ptr=7.7;
	

	// stack pointer of size int (4 bytes)
	int *stack_ptr;
	*stack_ptr=2;


	LOG("heap_ptr:" << heap_ptr)

	LOG("stack_ptr: " << stack_ptr)

	// must delete heap allocate to avoid memory leak
	delete heap_ptr;
  
}



sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'







	







	

	



