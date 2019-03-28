#include <bits/stdc++.h>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// Empty, Push, Pop, Top
class MinHeap{
  vector<int> item_;
  int Size(){
    return item_.size();
  }
  void MinHeapify(int cur){
    while(cur * 2 + 1 < Size()){
      int left = 2 * cur + 1;
      int right = 2 * cur + 2;
      int left_value = item_[2 * cur + 1];
      int right_value = right < Size() ? item_[right] : INT_MAX;
      int root_value = item_[cur];
      if(root_value > right_value || root_value > left_value){
        if(right_value > left_value){
          swap(item_[cur], item_[left]);
          cur = left;
        }else{
          swap(item_[cur], item_[right]);
          cur = right;
        }
      }else{
        break;
      }
    }
  }
  int Parent(int x){
    return (x - 1) / 2;
  }
public:
  MinHeap(){
    item_.clear();
  }
  bool Empty(){
    return Size() == 0;
  }
  int Top(){
    if(Size() == 0)
      throw runtime_error("Min heap is empty!");
    return item_[0];
  }
  void Pop(){
    if(Size() == 0)
      throw runtime_error("Min heap is empty!");
    swap(item_[0], item_[Size() - 1]);
    item_.pop_back();
    MinHeapify(0);
  }
  void Push(int x){
    item_.push_back(x);
    int cur = Size() - 1;
    while(cur > 0 && item_[Parent(cur)] > item_[cur]){
      swap(item_[Parent(cur)], item_[cur]);
      cur = Parent(cur);
    }
  }
};

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [&](const Interval& a, const Interval& b){
      return a.start < b.start;
    });
    MinHeap min_heap;
    int max_number_of_rooms = 0;
    int current_number_of_rooms = 0;
    for(int i = 0 ; i < (int)intervals.size() ; i++){
      int st = intervals[i].start;
      int en = intervals[i].end;
      if(!min_heap.Empty() && min_heap.Top() <= st){
        current_number_of_rooms--;
        min_heap.Pop();
      }
      current_number_of_rooms++;
      min_heap.Push(en);
      if(current_number_of_rooms > max_number_of_rooms)
        max_number_of_rooms = current_number_of_rooms;
    }
    return max_number_of_rooms;
  }
};