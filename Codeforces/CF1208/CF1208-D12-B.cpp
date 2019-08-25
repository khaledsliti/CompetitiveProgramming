#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

int n;
int arr[N];
int cnt = 0;
unordered_map<int, int> mp;

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
    mp[arr[i]]++;
  }
  for(auto x : mp)
    if(x.second > 1)
      cnt++;
  if(cnt == 0)
    return cout << 0 << endl, 0;
  int ans = 1e9;
  for(int i = 0 ; i < n ; i++){
    for(int j = i ; j < n ; j++){
      --mp[arr[j]];
      if(mp[arr[j]] == 1)
        cnt--;
      if(cnt == 0){
        ans = min(ans, j - i + 1);
      }
    }
    for(int j = i ; j < n ; j++){
      ++mp[arr[j]];
      if(mp[arr[j]] == 2)
        cnt++;
    }
  }
  cout << ans << endl;
  return 0;
}