#include <set>
using namespace std;

class MedianFinder {
  multiset<int> data;
  multiset<int>::iterator it1, it2;
    
public:
  MedianFinder() {
    it1 = data.end();
    it2 = data.end();
  }
    
  void addNum(int num) {
    data.insert(num);
    if(it1 == data.end()){
      it1 = it2 = data.begin();
    }else{
      if(num < *it1) { // before
        if(it1 == it2)
          it1--;
        else
          it2--;
      }else if(num < *it2){ // between
        it1++;
        it2--;
      }else{ // after
        if(it1 == it2)
          it2++;
        else
          it1++;
      }
    }
  }
  
  double findMedian() {
    return (*it1 + *it2) / 2.0;
  }
};
