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


void solve() {
  string s;
  cin >> s;
  int a = 0, b = 0;
  for(int i = 0; i < sz(s); i++) {
    if(s[i] == '0') a++;
    else b++;
  }
  a = min(a, b);
  if(a & 1) cout << "DA" << endl;
  else cout << "NET" << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
