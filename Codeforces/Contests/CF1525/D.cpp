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

const int N = 5007;
const int INF = 1e9;

vector<int> a, b;
int dp[N][N];

int solve(int i, int j) {
  if(i >= sz(a)) return 0;
  if(j >= sz(b)) return INF;
  int& r = dp[i][j];
  if(r != -1) return r;
  r = solve(i, j + 1);
  r = min(r, abs(a[i] - b[j]) + solve(i + 1, j + 1));
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(x) a.push_back(i);
    else b.push_back(i);
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
  return 0;
}
