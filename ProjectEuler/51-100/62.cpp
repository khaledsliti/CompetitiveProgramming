// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1000007;

int n, k;

int main()
{
  cin >> n >> k;
  unordered_map<string, vector<ll>> cubes;
  for(int i = 1; i < n; i++) {
    ll cur = 1LL * i * i * i;
    int cnt[10] = {0};
    for(ll tmp = cur; tmp > 0; tmp /= 10)
      cnt[tmp % 10]++;
    string s;
    for(int i = 0; i < 10; i++)
      while(cnt[i]--)
        s += char('0' + i);
    sort(all(s));
    cubes[s].push_back(cur);
  }
  vector<ll> sol;
  for(auto& item : cubes) {
    if(sz(item.second) == k) {
      sol.push_back(*min_element(all(item.second)));
    }
  }
  sort(all(sol));
  for(auto x : sol) printf("%lld\n", x);
  return 0;
}
