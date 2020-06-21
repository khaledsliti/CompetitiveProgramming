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

int const n = 8;
string s[n];

ll solve(int cur, int a, int b, int c) {
  if(cur >= n) return 1;
  ll res = 0;
  int msk = a | b | c;
  for(int i = 0; i < n; i++) {
    if(s[cur][i] == '*') continue;
    if(msk & (1 << i)) continue;
    res += solve(cur + 1, (a | (1 << i)) >> 1, b | (1 << i), ((c | (1 << i)) & ((1 << n) - 1)) << 1);
  }
  return res;
}

int main()
{
  for(int i = 0; i < n; i++)
    cin >> s[i];
  cout << solve(0, 0, 0, 0) << endl;
  return 0;
}
