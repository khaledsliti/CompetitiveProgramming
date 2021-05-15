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

const int N = 2007;

int n, m;
string s[N];
int dp[N][N], vis[N][N];

bool in(int i, int j) {
  return i < n && j < m;
}

int getValue(int i, int j) {
  return s[i][j] == '+' ? 1 : -1;
}

int solve(int i, int j) {
  int& r = dp[i][j];
  if(vis[i][j]) return r;
  vis[i][j] = 1;
  if(in(i + 1, j) && in(i, j + 1)) {
    r = max(getValue(i + 1, j) - solve(i + 1, j), getValue(i, j + 1) - solve(i, j + 1));
  } else if(in(i + 1, j)) {
    r = getValue(i + 1, j) - solve(i + 1, j);
  } else if(in(i, j + 1)) {
    r = getValue(i, j + 1) - solve(i, j + 1);
  } else {
    r = 0;
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }

  memset(vis, 0, sizeof vis);
  int r = solve(0, 0);

  if(r > 0) cout << "Takahashi" << endl;
  else if(r == 0) cout << "Draw" << endl;
  else cout << "Aoki" << endl;
  return 0;
}
