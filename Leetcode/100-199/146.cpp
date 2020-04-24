#include <bits/stdc++.h>
using namespace std;

class LRUCache {

  typedef list<pair<int, int>>::iterator list_iterator;
  typedef unordered_map<int, list_iterator>::iterator map_iterator;

  int capacity;
  list<pair<int, int>> values;
  unordered_map<int, list_iterator> keys;

  int Erase(int key) {
    auto it = keys.find(key);
    if(it == keys.end()) return -1;
    int value = it->second->second;
    values.erase(it->second);
    keys.erase(it);
    return value;
  }

  void Add(int key, int val) {
    values.push_front({ key, val });
    keys[key] = values.begin();
    if(values.size() > this->capacity) {
      keys.erase(values.back().first);
      values.pop_back();
    }
  }

  bool Exist(int key) {
    return keys.count(key) > 0;
  }
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
  }
  int get(int key) {
    if(!Exist(key))
      return -1;
    int value = Erase(key);
    Add(key, value);
    return value;
  }
  void put(int key, int value) {
    if(Exist(key)) Erase(key);
    Add(key, value);
  }
};

int main()
{

  return 0;
}