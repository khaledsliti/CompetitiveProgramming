class LRUCache {
  int capacity;
  list<pair<int, int>> used; // contains pairs <key, value>
  unordered_map<int, list<pair<int, int>>::iterator> keys; // contains keys

  void ChangeToFront(unordered_map<int, list<pair<int, int>>::iterator>::iterator it){
    if(it->second == used.begin())
      return;
    int key = it->second->first;
    int value = it->second->second;
    used.erase(it->second);
    used.push_front({ key, value });
    it->second = used.begin();
  }
  void EraseBack(){
    int key = used.back().first;
    keys.erase(key);
    used.pop_back();
  }
  int Size(){
    return used.size();
  }
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
  }
  int get(int key) {
    auto it = keys.find(key);
    if(it == keys.end())
      return -1;
    ChangeToFront(it);
    return used.front().second;
  }
  void put(int key, int value) {
    auto it = keys.find(key);
    if(it == keys.end()){ // put
      if(Size() == capacity){
        keys.erase(used.back().first);
        used.pop_back();
      }
      used.push_front({ key, value });
      keys.insert({ key, used.begin() });
    }else{ // set
      it->second->second = value;
      ChangeToFront(it);
    }
  }
};