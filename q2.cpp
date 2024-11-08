#include <iostream>
using namespace std;

class Base {
	public: virtual void iam() { cout << "Base\n"; } // Virtual function
};
class D1 : public Base {
	public: void iam() { cout << "D1\n"; }
};
class D2 : public Base {
	public: void iam() { cout << "D2\n"; }
};
void print(Base* bptr) { bptr->iam(); } // Calls the appropriate iam() function based on the object's actual type
int main() {
	Base b; D1 d1; D2 d2;
	print(&b);
	print(&d1);
	print(&d2);
}
