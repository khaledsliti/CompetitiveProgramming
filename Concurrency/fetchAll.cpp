// Guess Who's Back
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

class MyInt {
  int x;
public:
  MyInt(): x(0) {}
  explicit MyInt(int x): x(x) {}
  void set(int x) {
    this->x = x;
  }
  int get() const {
    return x;
  }
  int get() {
    return x;
  }
  friend ostream& operator<<(ostream& cout, const MyInt item) {
    cout << "myInt = " << item.x;
    return cout;
  }
  friend MyInt operator+(MyInt a, MyInt b) {
    return MyInt(a.x + b.x);
  }
  MyInt operator+=(MyInt rhs) {
    this->x += rhs.x;
    return *this;
  }
};

class A {
protected:
  int a;
public:
  A(int a): a(a) {
    cout << "A const" << endl;
  }
  virtual void print() {
    cout << a << endl;
  }
  ~A() {
    cout << "A dest" << endl;
  }
};

class B: public A {
int b;
public:
  B(int a, int b): A(a), b(b) {
    cout << "B const" << endl;
  }
  void print() {
    cout << a << " " << b << endl;
  }
  ~B() {
    cout << "B dest" << endl;
  }
};


class Base {
public:
  void printAny() {
    cout << "any" << endl;
  }
  virtual void print() = 0;
  ~Base() {
    cout << "Dest base" << endl;
  }
};

class derived: public Base {
public:
  void print() {
    cout << "print" << endl;
  }
  ~derived() {
    cout << "Dest derived" << endl;
  }
};


int main()
{
  shared_ptr<derived> d(new derived());

  d->print();

  return 0;
}
