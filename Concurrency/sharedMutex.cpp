// RedStone
#include <iostream>
#include <vector>
#include <mutex>
#include <shared_mutex>
#include <thread>
using namespace std;

const int LOOP_COUNT = 5000000;
const int READERS_THREADS = 8;

class shared_mutex_counter {
private:
  mutable shared_mutex mutex_;
  unsigned int value_ = 0;
public:
  int get() const {
    shared_lock<shared_mutex> lk(mutex_);
    return this->value_;
  }
  void increment() {
    unique_lock<shared_mutex> lk(mutex_);
    this->value_ ++;
  }
};

class mutex_counter {
private:
  mutable std::mutex mutex_;
  unsigned int value_ = 0;
public:
  int get() const {
    scoped_lock<mutex> lk(mutex_);
    return this->value_;
  }
  void increment() {
    scoped_lock<mutex> lk(mutex_);
    this->value_ ++;
  }
};

template <typename T>
void test_data_structure(const string& testName, T* pcounter) {
  int tmp;

  auto writer = [pcounter]() {
    for(int i = 0; i < 100; i++) {
      pcounter->increment();
    }
  };

  auto reader = [pcounter, &tmp]() {
    for(int i = 0; i < LOOP_COUNT; i++) {
      tmp = pcounter->get();
    }
  };

  clock_t start = clock();

  thread** tarray = new thread*[READERS_THREADS];
  for(int i = 0; i < READERS_THREADS; i++) {
    tarray[i] = new thread(reader);
  }

  thread tw(writer);

  for(int i = 0; i < READERS_THREADS; i++) {
    tarray[i]->join();
  }
  tw.join();

  clock_t end = clock();
  printf("[Test %s]\n", testName.c_str());
  printf("thread count: %d\n", READERS_THREADS);
  printf("result: %d, cost: %f s, tmp: %d\n", pcounter->get(), ((double)(end - start)) / CLOCKS_PER_SEC, tmp);
}

int main()
{
  test_data_structure("shard mutex", new shared_mutex_counter());
  test_data_structure("mutex", new mutex_counter());
  return 0;
}
