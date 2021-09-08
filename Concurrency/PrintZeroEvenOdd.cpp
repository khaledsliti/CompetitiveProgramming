#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class ZeroEvenOdd {
private:
  int n;
  mutex mt;
  condition_variable cv;
  int cur;
  bool printZero;

public:
  ZeroEvenOdd(int n) {
    this->n = n;
    cur = 1;
    printZero = 1;
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for(int i = 0; i < n; i++) {
      unique_lock<mutex> lk(mt);
      cv.wait(lk, [&]() { return printZero; });
      printNumber(0);
      printZero = !printZero;
      lk.unlock();
      cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    for(int i = 2; i <= n; i += 2) {
      unique_lock<mutex> lk(mt);
      cv.wait(lk, [&]() { return !printZero && cur % 2 == 0; });
      printNumber(cur);
      printZero = !printZero;
      cur++;
      lk.unlock();
      cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    for(int i = 1; i <= n; i += 2) {
      unique_lock<mutex> lk(mt);
      cv.wait(lk, [&]() { return !printZero && cur % 2 == 1; });
      printNumber(cur);
      printZero = !printZero;
      cur++;
      lk.unlock();
      cv.notify_all();
    }
  }
};

void print(int n) {
  cout << n << endl;
}

int main() {
  ZeroEvenOdd instance(6);

  thread A([&](){ instance.zero(print); });
  thread B([&](){ instance.even(print); });
  thread C([&](){ instance.odd(print); });

  A.join();
  B.join();
  C.join();

  return 0;
}
