// 20/10/16
#include <string>
#include <vector>
#include <map>
#include <array>
#include <memory>
#include <iostream>
#include <cstdint>


// INSTRUCTIONS 
enum Opcodes{
	iadd, isub, imul, imod, iunm, 
	eq, neq, lt, le, gt, ge,
	bnot, band, bor, bxor,
	jmp, rt, loadk, loadbool, mov, forloop, call
};


// OBJECTS
enum Types{
	Nil, BL, IX, UX, I8, U8, I16, U16,
	I32, U32, Ii64, U64, F32, F64, 
	DataTypeObj, 
	IndObj, 
	FuncObj, 
	Buffer, List, Map, Str, Chars
};


struct primObjInt{
	unsigned type;
	unsigned refCount;
	int value;
};

struct primObjUInt{
	unsigned type;
	unsigned refCount;
	int value;
};

struct funcObj{ // first class functions 
	unsigned index;
};

struct typeObj{ // first class type 
	unsigned index;
};


union any{
	primObjInt sint; primObjUInt uint; funcObj func; typeObj type;
};


//  STRUCTURES
struct function{
	unsigned instructionPosition;
	unsigned localsSize;
	unsigned globalsSize;
	std::unique_ptr<unsigned[]> globals;
	unsigned funcsLength;
	std::unique_ptr<unsigned[]>  funcs;
};

struct type{
	unsigned contentSize;
	std::unique_ptr<unsigned[]> parents;
};



// MAIN 
void initVM();
void printSizes();
int main(){
	printSizes();

	// TEST BEGIN
	void *ptr = new int[5];
	int *iptr = static_cast<int *>(ptr);
	iptr[0] = 34;
	std::cout << "ptr[1]: " << iptr[0] << std::endl;
	uint64_t  ue = 54;
	uint16_t ud = ue + 50;
	std::cout << "ux = 5000 + 5000: " << ud << std::endl;
	std::string sep = "--------------------\n";
	uint16_t targetA = 235, maskA = 15;
	uint16_t targetB = 26105, maskB = 4095;
	uint16_t targetC = 13, maskC = 9;
	uint16_t targetD = 30201, maskD = 61440;
	std::cout 
		<< "\n0000 0000 1110 1011 (235)\nAND\n0000 0000 0000 1111 (15)\n" << sep << "0000 0000 0000 1011 (11)\n" << sep << (targetA & maskA) << "\n"
		<< "\n0110 0101 1111 1001 (26105)\nAND\n0000 1111 1111 1111 (4095)\n" << sep << "0000 0101 1111 1001 (1529)\n" << sep << (targetB & maskB) << "\n"
		<< "\n0000 0000 0000 1101 (13) << 4\n0000 0000 1101 0000 (208)\nOR\n0000 0000 0000 1001 (9)\n" << sep << "0000 0000 1101 1001 (217)\n" << sep << ((targetC << 4) | maskC) << "\n"
		<< "\n0111 0101 1111 1001 (30201) >> 12\n" << sep << "0000 0000 0000 0111 (7)\n" << sep << (targetD  >> 12) << "\n"
		<< std::endl;
	any *prim;
	any x;
	x.sint.value = 67;
	prim = &x;
	std::cout << "any prim.sint.value: " << (*prim).sint.value << std::endl;
	any y;
	y.uint.value = -67;
	prim = &y;
	std::cout << "any prim.sint.value: " << (*prim).uint.value << std::endl;
	// TEST END

	std::cout << "¡bang! >> ";
	std::string input;
	std::cin >> input;
	std::cout << std::endl;
	
	
	delete []iptr;
	
	initVM();

	std::cin.get();
}


// THE VM
void vm(	
	const std::vector<uint32_t> &instructions,
	const std::vector<any> &globals,
	const std::map<unsigned, std::map<unsigned, function>> &funcMap,
	const std::map<unsigned, type> &typeMap
	 ){

	// STACKED
	std::array<any, 1000> stack;
	
}

void initVM(){
	unsigned instrSize = 0;
	unsigned globalsSize = 0;
	unsigned upValsSize = 0;
	
	// HEAPED
	std::vector<uint32_t> instructions;
	instructions.reserve(instrSize);
	std::vector<any> globals;
	globals.reserve(globalsSize);
	std::map<unsigned, std::map<unsigned, function>> funcMap; // multiple dispatch consideredx
	std::map<unsigned, type> typeMap;
	
	vm(instructions, globals, funcMap, typeMap);
}


void printSizes(){
	std::cout 
		<< "\t\tON THIS MACHINE\n"
		<< "***The size of a generic Bang object is: " << sizeof(any) << " bytes\n"
		<< "***The size of a Bang instruction is: " << sizeof(uint32_t) << " bytes\n"
		<< "***The width of a Bang stack is: " << sizeof(any) << " bytes\n"
		<< "***The size of a Bang int is: " << sizeof(primObjInt) << " bytes\n"
		<< "***The size of a Bang any pointer is: " << sizeof(any) << " bytes\n" ////////////////////////////
		<< "***The footprint of a Bang function is: " << sizeof(function) << " bytes\n"
		<< "***The footprint of a Bang type is: " << sizeof(type) << " bytes\n"
		<<"--------------------------------------------------\n"
		<< "***The size of C++ int is: " << sizeof(int) << " bytes\n"
		<< "***The size of C++ pointer is: " << sizeof(int*) << " bytes\n"
		<< std::endl;
}


// STACK MANAGEMENT
