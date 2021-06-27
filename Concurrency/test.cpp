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
            unique_lock lk(mt);
            cv.wait(lk, [&]() { return printZero; });
            printNumber(0);
            cerr << 0 << " ";
            printZero = !printZero;
            lk.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 0; i <= n; i += 2) {
            unique_lock lk(mt);
            cv.wait(lk, [&]() { return !printZero && cur % 2 == 0; });
            printNumber(cur);
            cerr << cur << " ";
            printZero = !printZero;
            cur++;
            lk.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i += 2) {
            unique_lock lk(mt);
            cv.wait(lk, [&]() { return !printZero && cur % 2 == 1; });
            printNumber(cur);
            cerr << cur << " ";
            printZero = !printZero;
            cur++;
            lk.unlock();
            cv.notify_all();
        }
    }
};

int main() {

  return 0;
}
