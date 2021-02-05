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

const int N = 5002;

string s, a, b;
int dp[N][N];

int solve(int i, int j) {
  if(i >= sz(a) && j >= sz(b)) return 1;
  int& r = dp[i][j];
  if(r != -1) return r;
  r = 0;
  if(i < sz(a) && s[i + j] == a[i]) {
    r = r || solve(i + 1, j);
  }
  if(j < sz(b) && s[i + j] == b[j]) {
    r = r || solve(i, j + 1);
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> s >> a >> b;

  memset(dp, -1, sizeof dp);
  cout << (solve(0, 0) ? "yes" : "no") << endl;
  return 0;
}
