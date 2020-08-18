// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e5 + 5;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  ll ans = 0;
  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int h = 0, ss = 0;
    for(int i = sz(s) - 1; i >= 0; i--) {
      if(s[i] == 'h') h++;
      else ans += h, ss++;
    }
    v.push_back({ss, h});
  }
  sort(all(v), [](const pair<int, int>& a, const pair<int, int>& b) {
    ll diff = 1LL * a.first * b.second - 1LL * a.second * b.first;
    return diff > 0;
  });
  int h = 0;
  for(int i = sz(v) - 1; i >= 0; i--) {
    ans += 1LL * v[i].first * h;
    h += v[i].second;
  }
  cout << ans << endl;
  return 0;
}
