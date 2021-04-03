// Guess Who's Back
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

const int L = 20;

string a, b;
long long dp[L][2][2][10][2];

string read() {
  long long x; cin >> x;
  string r = to_string(x);
  reverse(all(r));
  while(sz(r) < L) r += '0';
  reverse(all(r));
  return r;
}

long long solve(int i, int gt, int lt, int last, int f) {
  if(i >= L) return 1;
  long long& r = dp[i][gt][lt][last][f];
  if(r != -1) return r;
  r = 0;
  for(int d = 0; d <= 9; d++) {
    int c1 = gt || (d >= a[i] - '0');
    int c2 = lt || (d <= b[i] - '0');
    int c = (d == 0 && (d != last || !f)) || (d > 0 && d != last);
    if(c1 && c2 && c) {
      r += solve(i + 1, gt || (d > a[i] - '0'), lt || (d < b[i] - '0'), d, f || d > 0);
    }
  }
  return r;
}

int main()
{
  a = read();
  b = read();
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0, 9, 0) << endl;
  return 0;
}
