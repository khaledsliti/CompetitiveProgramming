#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, m;
pair<int, int> arr[N];
vector<int> res;

void solve()
{
  int right = 0;
  sort(arr, arr + n); // O(N log N)
  int idx = 0;
  while(right < m && idx < n){ // O(N)
    int new_right_at = -1;
    while(idx < n && arr[idx].first <= right){
      if(new_right_at == -1 || arr[new_right_at].second < arr[idx].second)
        new_right_at = idx;
      idx++;
    }
    if(new_right_at == -1){
      res.clear();
      return;
    }
    res.push_back(new_right_at);
    right = arr[new_right_at].second;
  }
  if(right < m)
    res.clear();
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &m);
    int x, y;
    n = 0;
    while(scanf("%d%d", &x, &y) && (x | y))
      arr[n++] = {x, y};
    res.clear();
    solve();
    printf("%d\n", sz(res));
    for(auto x : res)
      printf("%d %d\n", arr[x].first, arr[x].second);
    if(T)
      printf("\n");
  }
  return 0;
}
