// RedStone
#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>
using namespace std;

class shared_mutex_counter {
private:
  mutable std::shared_mutex mutex_;
  unsigned int value_ = 0;
public:
  int get() const {
    shared_lock<shared_mutex> lk(mx);
    return value_;
  }
  void reset() {

  }
};

int main()
{
  
  return 0;
}
