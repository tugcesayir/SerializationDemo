//Simple serialization in C++ by converting struct to byte array.
#include <iostream>
#include <string>

typedef struct {
	int a;
	double b;
	std::string::const_pointer s1; // Original project fixed
	char s2[50];
	float arr[3];
} MyStruct;

int main() {
	MyStruct m1;
	m1.a = 1;
	m1.b = 123;
	m1.s1 = "abc";
	strcpy_s(m1.s2, "def");
	m1.arr[0] = 10; m1.arr[1] = 20; m1.arr[2] = 30;

	//Serialize:
	const unsigned int MAX_SIZE_BYTES = 200;
	char byteArray[MAX_SIZE_BYTES];
	memcpy(byteArray, (char*)&m1 , sizeof(MyStruct)); //copy struct to char (byte) array

	//Deserialize:
	MyStruct m2;
	memcpy(&m2, byteArray, sizeof(MyStruct)); //copy char (byte) array to struct

	std::cout << "m1.s1: " << m1.s1 << std::endl;
	std::cout << "m2.s1: " << m2.s1 << std::endl;

	std::cout << "m1.s2: " << m1.s2 << std::endl;
	std::cout << "m2.s2: " << m2.s2 << std::endl;
	
	std::cout << "m1.arr[2]: " << m1.arr[2] << std::endl;
	std::cout << "m2.arr[2]: " << m2.arr[2] << std::endl;
	
	std::cout << "Press enter..." << std::endl;
	std::cin.get();
}