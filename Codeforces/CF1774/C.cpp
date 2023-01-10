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

const int N = 2e5 + 5;

int n;
string s;

void solve() {
  cin >> n;
  cin >> s;
  int z = 0, lz = -1, o = 0, lo = -1;
  for(int i = 0; i < n - 1; i++) {
    if(s[i] == '0') {
      z++;
      lz = i;
      cout << lo + 2 << " ";
      continue;
    }
    o++;
    lo = i;
    cout << lz + 2 << " ";
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
