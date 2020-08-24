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

const int N =2e5 + 5;

string s, t;
int p[N], d[N];

bool check(int cnt) {
  for(int i = 0; i < sz(s); i++) {
    d[i] = 0;
  }
  for(int i = 0; i < cnt; i++) {
    d[p[i]] = 1;
  }
  int j = 0;
  for(int i = 0; i < sz(s) && j < sz(t); i++) {
    if(d[i]) continue;
    if(s[i] == t[j])
      j++;
  }
  return j >= sz(t);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s >> t;
  for(int i = 0; i < sz(s); i++) {
    cin >> p[i];
    --p[i];
  }
  int l = 0, r = sz(s), ans = -1;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  assert(ans != -1);
  cout << ans << endl;
  return 0;
}
