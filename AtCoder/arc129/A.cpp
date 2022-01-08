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

const int MAX = 60;

vector<int> N, L, R;

long long dp[MAX][2][2][2];

vector<int> toBin(long long x) {
  vector<int> r;
  for(int i = 0; i < MAX; i++) {
    r.push_back((x & 1));
    x >>= 1;
  }
  reverse(all(r));
  return r;
}

long long solve(int i, int l, int r, int n) {
  // debug(i, l, r, n);
  if(i >= MAX) {
    return n == 1;
  }
  long long& res = dp[i][l][r][n];
  if(res != -1) return res;
  res = 0;
  // put 0
  if(l || L[i] == 0) {
    // cout << "put 0" << endl;
    res += solve(i + 1, l, r || R[i] == 1, n);
  }
  // put 1
  if((r || R[i] == 1) && (n || N[i] == 1)) {
    // cout << "put 1" << endl;
    res += solve(i + 1, l || L[i] == 0, r, 1);
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  long long N, L, R;
  cin >> N >> L >> R;
  ::N = toBin(N);
  ::L = toBin(L);
  ::R = toBin(R);

  // debug(::L), debug(::R), debug(::N);

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0, 0, 0) << endl;

  return 0;
}
