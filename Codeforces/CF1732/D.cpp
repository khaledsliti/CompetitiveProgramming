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

int q;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> q;
  set<long long> s;
  s.insert(0);
  map<long long, long long> mex;
  while(q--) {
    char c; long long k;
    cin >> c >> k;
    if(c == '+') {
      s.insert(k);
    } else {
      while(s.count(mex[k])) {
        mex[k] += k;
      }
      cout << mex[k] << endl;
    }
  }
  return 0;
}
