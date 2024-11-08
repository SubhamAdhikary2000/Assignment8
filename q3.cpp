#include <iostream>
using namespace std;
class Char_vec {
protected:
    int sz;
    char* element;

public:
    static Char_vec* new_char_vec(int s);

    virtual char& operator[](int i) {
        return element[i];
    }

    Char_vec(int s) : sz(s), element(new char[s]) {}

    virtual ~Char_vec() {
        delete[] element;
    }
};

class Char_vec_derived : public Char_vec {
public:
    Char_vec_derived(int size, char* e) : Char_vec(size) {
        element = e;
    }

    char& operator[](int i) override {
        return element[i];
    }
};

Char_vec* Char_vec::new_char_vec(int s) {
    char* e = new char[s];
    for (int i = 0; i < s; ++i) {
        e[i] = 'a' + i;
    }

    Char_vec* c = new Char_vec_derived(s, e);
    return c;
}

int main() {
    Char_vec* cobj = Char_vec::new_char_vec(3);
    for (int i = 0; i < 3; ++i) {
        cout << cobj->operator[](i) <<endl;
    }

    delete cobj;
    return 0;
}
