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

const int N = 105;
const int S = 10005;

int n, s;
int a[N], b[N];
int dp[N][S];

int solve(int i, int rem) {
  if(i >= n) {
    return rem == 0;
  }
  int& r = dp[i][rem];
  if(r != -1) return r;
  if(rem >= a[i] && solve(i + 1, rem - a[i])) {
    return r = 1;
  }
  if(rem >= b[i] && solve(i + 1, rem - b[i])) {
    return r = 1;
  }
  return r = 0;
}

void trace(int i, int rem) {
  if(i >= n) return;
  if(rem >= a[i] && solve(i + 1, rem - a[i])) {
    cout << "H";
    trace(i + 1, rem - a[i]);
  } else {
    cout << "T";
    trace(i + 1, rem - b[i]);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  memset(dp, -1, sizeof dp);
  if (solve(0, s)) {
    cout << "Yes" << endl;
    trace(0, s);
    cout << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
