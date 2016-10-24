// 24/10/16
#include "bobject.h"
//------------------
#include <string>
#include <vector>
#include <map>
#include <array>
#include <memory>
#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::unique_ptr;
using std::vector;
using std::map;
using std::array;


// MAIN 
void vm();
int main(){
	vm();
	cin.get();
	return 0; 
}


// THE VM
void vm(){


	/// TEST 3
	int OP_ADD(1);
	int OP_SUB(2);
	int OP_MUL(3);
	int OP_DIV(4);

	int instruction = 4;

	any *vptra = (any *)malloc(sizeOfAny);
	primObjF32 a = vptra->f32; a.value = 0.0f;
	any *vptrb = (any *)malloc(sizeOfAny);
	primObjF32 b = vptra->f32; b.value = 51.0f;
	any *vptrc = (any *)malloc(sizeOfAny);
	primObjF32 c = vptra->f32; c.value = 22.0f;

	if(instruction == OP_ADD){
		a.value = b.value + c.value;
	}
	else if(instruction == OP_SUB){
		a.value = b.value - c.value;
	}
	else if(instruction == OP_MUL){
		a.value = b.value * c.value;
	}
	else if(instruction == OP_DIV){
		a.value = b.value / c.value;
	}

	cout << "Slot a contains: " << a.value << endl;

	free(vptra);
	free(vptrb);
	free(vptrc);

	/// TEST 2
	//int OP_ADD(1);
	//int OP_SUB(2);
	//int OP_MUL(3);
	//int OP_DIV(4);

	//int instruction = 1;

	//void *vptra = new int;
	//int *a = (int *) vptra;

	//void *vptrb = new int(20);
	//int *b = (int *)vptrb;

	//void *vptrc = new int(79);
	//int *c = (int *)vptrc;

	//if(instruction == OP_ADD){
	//	*a = (*b) + (*c);
	//}
	//else if(instruction == OP_SUB){
	//	*a = (*b) - (*c);
	//}
	//else if(instruction == OP_MUL){
	//	*a = (*b) * (*c);
	//}
	//else if(instruction == OP_DIV){
	//	*a = (*b) / (*c);
	//}

	//cout << "Slot a contains: " << (*a) << endl;

	//delete a;
	//delete b;
	//delete c;

	/// TEST 1
	//int OP_ADD(1);
	//int OP_SUB(2);
	//int OP_MUL(3);
	//int OP_DIV(4);

	//int instruction = 1;

	//primObjSint a; a.value = 0;
	//primObjSint b; b.value = 67;
	//primObjSint b; b.value = 23;

	//if(instruction == OP_ADD){
	//	a.value = b.value + c.value;
	//}
	//else if(instruction == OP_SUB){
	//	a.value = b.value - c.value;
	//}
	//else if(instruction == OP_MUL){
	//	a.value = b.value * c.value;
	//}
	//else if(instruction == OP_DIV){
	//	a.value = b.value / c.value;
	//}

	//cout << "Slot a contains: " << a.value << endl;

}

void initVM(){
}