// Guess Who's Back
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

class FizzBuzz {
private:
  int n;

  mutex mt;
  condition_variable cond;
  int curVal;

  void doWork(function<bool(int)> test, function<void(int)> print) {
    while(true) {
      unique_lock<mutex> lk(mt);
      cond.wait(lk, [&](){ return curVal > n || test(curVal); });
      if(curVal > n) return;
      print(curVal);
      curVal++;
      lk.unlock();
      cond.notify_all();
    }
  }

public:
  FizzBuzz(int n) {
    this->n = n;
    curVal = 1;
  }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    doWork([&](int v) { return v % 3 == 0 && v % 5 != 0; }, [&](int v){ printFizz(); });
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    doWork([&](int v) { return v % 3 != 0 && v % 5 == 0; }, [&](int v){ printBuzz(); });
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    doWork([&](int v) { return v % 3 == 0 && v % 5 == 0; }, [&](int v){ printFizzBuzz(); });
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    doWork([&](int v) { return v % 3 != 0 && v % 5 != 0; }, printNumber);
  }
};

int main()
{
  FizzBuzz instance(20);

  thread A(&FizzBuzz::fizz, &instance, [](){ cout << "fizz" << endl; });
  thread B(&FizzBuzz::buzz, &instance, [](){ cout << "buzz" << endl; });
  thread C(&FizzBuzz::fizzbuzz, &instance, [](){ cout << "fizzbuzz" << endl; });
  thread D(&FizzBuzz::number, &instance, [](int x){ cout << x << endl; });

  A.join(); B.join(); C.join(); D.join();
  return 0;
}
