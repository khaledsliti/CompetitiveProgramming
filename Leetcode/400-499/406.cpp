class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
      if(a.first == b.first)
        return a.second < b.second;
      return a.first > b.first;
    });
    for(int i = 1 ; i < (int)people.size() ; i++){
      int idx = people[i].second;
      for(int k = i ; k > idx ; k--)
        swap(people[k], people[k - 1]);
    }
    return people;
  }
};