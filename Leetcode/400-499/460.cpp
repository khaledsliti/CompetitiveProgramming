#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
  int capacity;
  int currentMin;                                 // the min freq
  unordered_map<int, pair<int, int>> mp;          // key: key, value: <value, freq>
  unordered_map<int, list<int>> freq;             // key: freq, value: list<key> the list of keys with freq
  unordered_map<int, list<int>::iterator> it;     // key: key, value: iterator for key position in freq list

  void addFreq(int key) { // add +1 to freq of the key
    int& keyFreq = mp[key].second;
    auto keyIt = it[key];
    freq[keyFreq].erase(keyIt); // erase the old iterator
    it[key] = freq[keyFreq + 1].insert(freq[keyFreq + 1].end(), key); // insert the key in the next freq and add its iterator
    if(freq[currentMin].empty()) // if the list if empty then we increased the freq of the last element with min freq
      currentMin++;
    ++keyFreq; // update the freq of the key
  }

  void eraseMinFreq() { // erase the minimum freq key - just erase the key from all hashmaps
    int key = *freq[currentMin].begin();
    it.erase(key);
    freq[currentMin].erase(freq[currentMin].begin());
    mp.erase(key);
  }

public:
  LFUCache(int capacity) {
    this->capacity = capacity;
  }

  int get(int key) {
    if (mp.count(key) == 0)
      return -1;
    addFreq(key);
    return mp[key].first;
  }

  void put(int key, int value) {
    if(capacity <= 0)
      return;
    if (mp.count(key)) {
      mp[key].first = value;
      addFreq(key);
    } else {
      if((int) mp.size() == capacity)
        eraseMinFreq();
      currentMin = 1; // the freq of the new added key
      mp.insert({ key, { value, 1 } });
      it[key] = freq[1].insert(freq[1].end(), key);
    }
  }
};

int main()
{
  LFUCache cache = LFUCache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  cout << cache.get(3) << endl;
  cache.put(4, 4);
  cout << cache.get(1) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(4) << endl;
  return 0;
}
