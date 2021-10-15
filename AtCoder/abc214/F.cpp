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

const int N = 2e5 + 5;
const int A = 26;
const int Mod = 1e9 + 7;

int n;
char s[N];
int pos[A][N];
int dp[N];

int solve(int i) {
  if(i >= n) return 0;
  int& r = dp[i];
  if(r != -1) return r;
  r = 0;
  for(int c = 0; c < A; c++) {
    if(pos[c][i] < n) {
      r += (1 + solve(pos[c][i] + 2)) % Mod;
      r %= Mod;
    }
  }
  return r;
}

int bf() {
  set<string> a;
  for(int mask = 1; mask < (1 << n); mask++) {
    bool ok = true;
    for(int j = 0; j + 1 < n; j++) {
      if((mask & (1 << j)) != 0 && ((mask & (1 << (j + 1)))) != 0) {
        ok = false;
      }
    }
    if(!ok) continue;

    string sub = "";
    for(int j = 0; j < n; j++) {
      if(mask & (1 << j)) {
        sub += s[j];
      }
    }
    a.insert(sub);
  }
  return a.size();
}

int main()
{
  scanf("%s", s);
  n = strlen(s);

  for(int i = 0; i < A; i++) {
    pos[i][n] = n;
  }

  for(int i = 0; i < A; i++) {
    for(int j = n - 1; j >= 0; j--) {
      if(s[j] == char(i + 'a')) {
        pos[i][j] = j;
      } else {
        pos[i][j] = pos[i][j + 1];
      }
    }
  }

  memset(dp, -1, sizeof dp);

  cout << solve(0) << endl;
  // cout << bf() << endl;
  return 0;
}
