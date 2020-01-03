#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 4;

int n;
vector<pair<long long, int>> arr;
long long ans[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    arr.pb({a, 0});
    arr.pb({b, 1});
  }
  sort(all(arr));
  // for(auto x : arr)
  //   cout << x.first << " " << x.second << endl;
  // cout << endl;
  int cur_number = 0;
  for(int i = 0 ; i < sz(arr) ; i++){
    int add1 = 0, del1 = 0;
    int j = i;
    while(j < sz(arr) && arr[i].first == arr[j].first){
      if(arr[j].second == 0)
        ++add1;
      else
        ++del1;
      ++j;
    }
    // cout << i << " " << j << " " << add1 << " " << del1 << " " << cur_number << endl;
    cur_number += add1;
    ans[cur_number]++;
    cur_number -= del1;
    if(j < sz(arr))
      ans[cur_number] += arr[j].first - arr[i].first - 1;
    i = j - 1;
  }
  // cout << cur_number << endl;
  assert(cur_number == 0);
  for(int i = 1 ; i <= n ; i++)
    printf("%I64d ", ans[i]);
  return 0;
}
