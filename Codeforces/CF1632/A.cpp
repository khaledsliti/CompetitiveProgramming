// RedStone
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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    int n; cin >> n;
    string s; cin >> s;
    if(n >= 3) {
      cout << "NO" << endl;
    } else if(n == 1) {
      cout << "YES" << endl;
    } else {
      if(s == "01" || s == "10") cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
  return 0;
}
