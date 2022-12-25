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

const int N = 1e5 + 5;

int n, m;
int s[N];
int x[N];
set<int> xs;
int dp[N][10];
ll pref[N];
int nxt[N][10][10];

int getNext(int i, int j, int k) {

}

int solve(int i, int j) {
  int& r = dp[i][j];
  if(r != -1) return r;
  r = 1;
  for(int k = 0; k < m; k++) {
    int idx = nxt[i][j][k];
    if(idx < n) {
      r = max(r, 1 + solve(idx, k));
    }
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n - 1; i++) {
    cin >> s[i];
    pref[i] = s[i];
    if(i > 0) {
      pref[i] -= pref[i - 1];
    }
  }
  
  for(int i = 0; i < m; i++) {
    cin >> x[i];
  }

  map<ll, int> cnt;

  for(int j = 0; j < m; j++) {
    cnt[x[j]]++;
  }

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(i & 1) {
        cnt[pref[i - 1] - x[j]]++;
      } else {
        cnt[x[j] - pref[i - 1]]++;
      }
    }
  }

  int ans = 0;
  for(auto x: cnt) {
    ans = max(ans, x.second);
  }
  cout << ans << endl;

  return 0;
}
