#include <bits/stdc++.h>
using namespace std;
 
const int N = 3e6 + 5;
int n, w;
 
struct bag{
  map<int, int> mp;
  void add(int x){
    mp[x]++;
  }
  void del(int x){
    mp[x]--;
    if(!mp[x])
      mp.erase(x);
  }
  int get_max(int col, int len_arr){
    if(mp.size() == 0)
      return 0;
    int val = mp.rbegin()->first;
    if(val < 0 && (col >= len_arr || col < w - len_arr))
      return 0;
    return val;
  }
};


int len[N];
vector<pair<int, int>> add[N], del[N];
bag bags[N];
long long ans[N];
 
int main()
{
  scanf("%d%d", &n, &w);
  for(int i = 0 ; i < n ; i++){
    int l;
    scanf("%d", &l);
    len[i] = l;
    for(int j = 0 ; j < l ; j++){
      int a;
      scanf("%d", &a);
      add[j].push_back({i, a});
      del[w - l + j + 1].push_back({i, a});
    }
  }
  long long cur = 0;
  for(int idx = 0 ; idx < w ; idx++){
    for(auto& p : del[idx]){
      int row = p.first;
      int val = p.second;
      cur -= bags[row].get_max(idx - 1, len[row]);
      bags[row].del(val);
      cur += bags[row].get_max(idx, len[row]);
    }
    for(auto& p : add[idx]){
      int row = p.first;
      int val = p.second;
      cur -= bags[row].get_max(idx - 1, len[row]);
      bags[row].add(val);
      cur += bags[row].get_max(idx, len[row]);
    }
    ans[idx] = cur;
  }
  for(int i = 0 ; i < w ; i++)
    printf("%I64d ", ans[i]);
  printf("\n");
  return 0;
}
