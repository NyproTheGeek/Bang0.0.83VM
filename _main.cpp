//// 20/10/16
//#include <string>
//#include <vector>
//#include <map>
//#include <array>
//#include <memory>
//#include <iostream>
//#include <cstdint>
//
//using std::cout; 
//using std::endl; 
//using std::cin;
//using std::string;
//using std::unique_ptr;
//using std::vector;
//using std::map;
//
//// INSTRUCTIONS 
//enum Opcodes{
//	iadd, isub, imul, imod, iunm, 
//	eq, neq, lt, le, gt, ge,
//	bnot, band, bor, bxor,
//	jmp, rt, loadk, loadbool, mov, forloop, call
//};
//
//
//// OBJECTS
//enum Types{
//	Nil, BL, IX, UX, I8, U8, I16, U16,
//	I32, U32, Ii64, U64, F32, F64, 
//	DataTypeObj, 
//	IndObj, 
//	FuncObj, 
//	Buffer, List, Map, Str, Chars
//};
//
//
//struct primObjInt{
//	unsigned type;
//	unsigned refCount;
//	int value;
//};
//
//struct primObjUInt{
//	unsigned type;
//	unsigned refCount;
//	unsigned value;
//};
//
//struct primObjf32{
//	unsigned type;
//	unsigned refCount;
//	float value;
//};
//
//struct funcObj{ // first class functions 
//	unsigned index;
//};
//
//struct typeObj{ // first class type 
//	unsigned index;
//};
//
//
//union any{
//	primObjf32 f32;  primObjInt sint; primObjUInt uint; funcObj func; typeObj type;
//};
//
//
////  STRUCTURES
//struct function{
//	unsigned instructionPosition;
//	unsigned localsSize;
//	unsigned globalsSize;
//	unique_ptr<unsigned[]> globals;
//	unsigned funcsLength;
//	unique_ptr<unsigned[]>  funcs;
//};
//
//struct type{
//	unsigned contentSize;
//	unique_ptr<unsigned[]> parents;
//};
//
//
//
//// MAIN 
//void _initVM();
//void printSizes();
//int _main(){
//	printSizes();
//
//	// TEST BEGIN
//	uint64_t  ue = 54;
//	uint16_t ud = ue + 50;
//	cout << "ux = 5000 + 5000: " << ud << endl;
//	string sep = "--------------------\n";
//	uint16_t targetA = 235, maskA = 15;
//	uint16_t targetB = 26105, maskB = 4095;
//	uint16_t targetC = 13, maskC = 9;
//	uint16_t targetD = 30201, maskD = 61440;
//	cout
//		<< "\n0000 0000 1110 1011 (235)\nAND\n0000 0000 0000 1111 (15)\n" << sep << "0000 0000 0000 1011 (11)\n" << sep << (targetA & maskA) << "\n"
//		<< "\n0110 0101 1111 1001 (26105)\nAND\n0000 1111 1111 1111 (4095)\n" << sep << "0000 0101 1111 1001 (1529)\n" << sep << (targetB & maskB) << "\n"
//		<< "\n0000 0000 0000 1101 (13) << 4\n0000 0000 1101 0000 (208)\nOR\n0000 0000 0000 1001 (9)\n" << sep << "0000 0000 1101 1001 (217)\n" << sep << ((targetC << 4) | maskC) << "\n"
//		<< "\n0111 0101 1111 1001 (30201) >> 12\n" << sep << "0000 0000 0000 0111 (7)\n" << sep << (targetD  >> 12) << "\n"
//		<< endl;
//	any *prim = (any *)malloc(1 * sizeof(any));
//	prim->f32.value = 27.3;
//	cout << "any prim.f32.value: " << (*prim).f32.value << endl;
//	free(prim);
//	prim = (any *)malloc(1 * sizeof(any));
//	prim->uint.value = -27;
//	cout << "any prim.uint.value: " << (*prim).uint.value << endl;
//	free(prim);
//
//	void *pon = new primObjf32;
//	primObjf32 *star = (primObjf32 *)pon;
//	star->value = 23.7;
//	cout << "starf32: " << star->value << endl;
//
//	delete star;
//	// TEST END
//
//	cout << "¡bang! >> ";
//	string input;
//	cin >> input;
//	cout << endl;
//	
//	_initVM();
//
//	cin.get();
//
//	return 0;
//}
//
//
//// THE VM
//void _vm(	
//	const vector<uint32_t> &instructions,
//	const vector<any> &globals,
//	const map<unsigned, map<unsigned, function>> &funcMap,
//	const map<unsigned, type> &typeMap
//	 ){
//
//	// STACKED
//	std::array<any, 1000> stack;
//	
//}
//
//void _initVM(){
//	unsigned instrSize = 0;
//	unsigned globalsSize = 0;
//	unsigned upValsSize = 0;
//	
//	// HEAPED
//	vector<uint32_t> instructions;
//	instructions.reserve(instrSize);
//	vector<any> globals;
//	globals.reserve(globalsSize);
//	map<unsigned, map<unsigned, function>> funcMap; // multiple dispatch consideredx
//	map<unsigned, type> typeMap;
//	
//	_vm(instructions, globals, funcMap, typeMap);
//}
//
//
//void printSizes(){
//	cout 
//		<< "\t\tON THIS MACHINE\n"
//		<< "***The size of a generic Bang object is: " << sizeof(any) << " bytes\n"
//		<< "***The size of a Bang instruction is: " << sizeof(uint32_t) << " bytes\n"
//		<< "***The width of a Bang stack is: " << sizeof(any) << " bytes\n"
//		<< "***The size of a Bang int is: " << sizeof(primObjInt) << " bytes\n"
//		<< "***The size of a Bang any pointer is: " << sizeof(any) << " bytes\n" ////////////////////////////
//		<< "***The footprint of a Bang function is: " << sizeof(function) << " bytes\n"
//		<< "***The footprint of a Bang type is: " << sizeof(type) << " bytes\n"
//		<<"--------------------------------------------------\n"
//		<< "***The size of C++ int is: " << sizeof(int) << " bytes\n"
//		<< "***The size of C++ pointer is: " << sizeof(int*) << " bytes\n"
//		<< endl;
//}
//
//
//// STACK MANAGEMENT
