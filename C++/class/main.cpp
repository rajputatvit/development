#include <iostream>
#include "class.h"
using namespace std;

int main()
{
	A *aa = new A();
	A *bb = new B();
	A*cc = new C();
	A a;
	B b;
	C c;

	cout << "size aa" << sizeof(a) << endl;
	cout << "size bb" << sizeof(b) << endl;
	cout << "size cc" << sizeof(c) << endl;

	return 0;
}