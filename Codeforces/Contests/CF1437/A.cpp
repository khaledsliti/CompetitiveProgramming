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
  int T;
  cin >> T;
  while(T--) {
    int l, r;
    cin >> l >> r;
    if(l >= r + 1 - ((r + 1) / 2)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
