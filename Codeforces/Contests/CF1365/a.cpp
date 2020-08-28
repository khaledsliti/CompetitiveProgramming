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

const int N = 55;

int n, m;
string s[N];

void solve() {
  cin >> n >> m;
  vector<int> r(n, 0), c(m, 0);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int a; cin >> a;
      if(a) r[i] = c[j] = 1;
    }
  }
  int a = 0, b = 0;
  for(int i = 0; i < n; i++)
    a += r[i] == 0;
  for(int j = 0; j < m; j++)
    b += c[j] == 0;
  int t = min(a, b);
  if(t & 1) cout << "Ashish" << endl;
  else cout << "Vivek" << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
