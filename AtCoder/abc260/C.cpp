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

int n, x, y;

long long solve(int t, int n) {
  if(n == 1) {
    return t == 0 ? 0 : t;
  }
  if(t == 0) {
    return solve(0, n - 1) + x * solve(1, n);
  } else {
    return solve(0, n - 1) + y * solve(1, n - 1);
  }
}

int main()
{
  cin >> n >> x >> y;
  cout << solve(0, n) << endl;
  return 0;
}
