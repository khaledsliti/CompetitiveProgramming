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

const int N = 1001;

int main()
{
  int n, m;
  cin >> n >> m;
  set<string> s;
  for(int i = 0; i < m;i ++) {
    string t;
    cin >> t;
    s.insert(t);
  }
  vector<int> v;
  for(auto& x: s) {
    v.pb(sz(x));
  }
  sort(all(v));
  for(int i = 1; i < sz(v); i++)
    ++v[i];
  int ans = 0;
  for(int i = 0; i < sz(v); i++) {
    if(v[i] > n) {
      break;
    }
    n -= v[i];
    ans++;
  }
  cout << ans << endl;
  return 0;
}
