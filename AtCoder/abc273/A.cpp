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
  int n; cin >> n;
  int ans = 1;
  while(n > 0) {
    ans *= n;
    n--;
  }
  cout << ans << endl;
  return 0;
}
