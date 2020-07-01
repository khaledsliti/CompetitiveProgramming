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

const int N = 1e6 + 5;

int n;
string a, b;

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  string s;
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i]) {
      s += a[i];
    }
  }
  if(sz(s) & 1) {
    cout << -1 << endl;
    return 0;
  }
  if(!sz(s)) {
    cout << 0 << endl;
    return 0;
  }
  set<int> A, B;
  for(int i = 0; i < sz(s); i++)
    if(s[i] == '0') A.insert(i);
    else B.insert(i);
  
  int ans = 0;
  while(sz(A)) {
    ans++;
    set<int>& x = (*A.begin() < *B.begin()) ? A : B;
    set<int>& y = (*A.begin() < *B.begin()) ? B : A;
    int last = -1;
    while(sz(x)) {
      auto itx = x.lower_bound(last);
      if(itx == x.end()) break;
      auto ity = y.lower_bound(*itx);
      if(ity == y.end()) break;
      last = *ity;
      x.erase(itx);
      y.erase(ity);
    }
  }

  cout << ans << endl;
  return 0;
}
