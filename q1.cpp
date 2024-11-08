#include<iostream>
#include <vector>
#include <list>
using namespace std;
class base
{
int x;
vector<double> v;
public:
base(int y, vector<double> z): x {y}, v {z}{}
// getter for x
int getterX() const
{
return x;
}
// getter for v
vector<double> getterV() const
{
return v;
}
};
class derived : public base {
list<bool> l;
public:
derived(int y, vector<double> z):base{y,z},l{}{} // initializes an empty list
derived(int y, vector<double> z, list<bool> el):base{y,z},l{el}{}
void print()
{
//Printing the members of the base class.
cout<<" x is:"<<getterX()<<endl;
cout<<" v is:";
for (double num : getterV())
{
  cout << num << " ";
}
cout << endl;
// Print members of the derived class
cout <<"l is:";
for (bool val : l)
{
 cout << (val? "true":"false") << " ";
}
cout << endl;
}
};
int main()
{
derived d {10, {1.5, 2.5, 3.5}, {true, false}};
d.print();
}
