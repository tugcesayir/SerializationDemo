# SerializationDemo
Code bug fixed

1- C++ Code:
It serializes a Struct by converting it to a byte array so it can be stored in memory.

2-Code Error
The code is Debugged and Run, but the error is given when pressing Enter:

Exception thrown at 0x00007FF78B8B4C25 in SerializationDemo.exe: 0xC0000005: Access violation reading location 0xFFFFFFFFFFFFFFFF.

![image](https://user-images.githubusercontent.com/99322473/191608782-0957e44c-f93d-4014-9f58-2dd458f93a6b.png)

3-Cause of Code Error

![image](https://user-images.githubusercontent.com/99322473/191608870-39f153b2-8b92-4226-89d6-ef63b07298ca.png)

Access violation reading location means, pointer "points to" nothing. Pointer does not have an address or reference.
We cannot define the “std::string s1”. This is because the string class must have a reference, a fixed place in memory.
With std::string s1 definition, the class will only initially return an empty definition and attempt to assign a 0x0 position in memory.
However, the system does not accept this. The system does not allow the definition of unassigned memory for the class allocated. 
We need to tell the system that we will assign a value to the object we defined and that the memory will not be empty. 

4-Solution
a)Strings are objects that represent sequences of characters.

The standard string class provides support for such objects with an interface similar to that of a standard container of bytes, 
but adding features specifically designed to operate with strings of single-byte characters.
C++ has two types of strings:
1. C-style string
2. The C++ <string> class, which is the standard C++ string.
When we use the term string in C, we are talking about a variable-length array of characters. It has a starting point and ends with a string of terminating characters. 
Strings are immutable--the contents of a string object cannot be changed after the object is created, although the syntax makes it appear as if you can do this.
According to the C++ standard, the effect of attempting to modify a string literal is undefined. Therefore, we should always declare a pointer to a 
string literal as const char *.

![image](https://user-images.githubusercontent.com/99322473/191609017-3347003f-70b2-490f-903d-2db858ad89e5.png)

To fix the error in the code we need to add a constant reference to our String structure. We mark our String structure as const. 
We tell our immutable string structure that we want to allocate a free space in memory. So the system understands that memory will not be wasted and 
will assign a "value" to a constant definition.

Tuğçe Sayır


