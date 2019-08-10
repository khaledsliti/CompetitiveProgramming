#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n;
  cin >> n;
  map<string, int> mp;
  for(int i = 0 ; i < n ; i++){
    string s;
    cin >> s;
    sort(all(s));
    mp[s]++;
  }
  long long ans = 0;
  for(auto& x : mp){
    int cnt = x.second;
    ans += 1LL * cnt * (cnt - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
