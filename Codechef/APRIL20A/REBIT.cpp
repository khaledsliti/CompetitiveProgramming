// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100010;
const int Mod = 998244353;

#define A 2
#define Ab 3

long long myPow(long long a, long long b) {
  if(!b) return 1;
  long long r = myPow(a, b >> 1);
  r = (r * r) % Mod;
  if(b & 1) r = (r * a) % Mod;
  return r;
}

int n;
char s[N];
int en[N], op[N];
long long dp[N][4];

void solve() {
  scanf("%s", s);
  n = strlen(s);
  for(int i = 0 ; i < n ; i++)
    en[i] = -1;
  stack<int> st;
  for(int i = 0 ; i < n ; i++) {
    if(s[i] == '(') st.push(i);
    else if(s[i] == ')') {
      en[st.top()] = i;
      st.pop();
    } else if(s[i] != '#') op[st.top()] = i;
  }
  for(int i = n - 1 ; i >= 0 ; i--) {
    if(s[i] == '#') {
      for(int j = 0 ; j < 4 ; j++)
        dp[i][j] = 1;
    } else if(en[i] != -1) {
      int a = i + 1;
      int b = op[i] + 1;
      if(s[op[i]] == '&') {
        dp[i][0] = (dp[a][0] * (dp[b][0] + dp[b][1] + dp[b][A] + dp[b][Ab]) % Mod
                  + dp[a][1] * dp[b][0] % Mod
                  + dp[a][A] * (dp[b][Ab] + dp[b][0]) % Mod
                  + dp[a][Ab] * (dp[b][A] + dp[b][0]) % Mod) % Mod;
        dp[i][1] = (dp[a][1] * dp[b][1]) % Mod;
        dp[i][A] = (dp[a][1] * dp[b][A] % Mod + dp[a][A] * (dp[b][1] + dp[b][A])) % Mod;
        dp[i][Ab] = (dp[a][1] * dp[b][Ab] % Mod + dp[a][Ab] * (dp[b][1] + dp[b][Ab])) % Mod;
      }
      if(s[op[i]] == '|') {
        dp[i][0] = (dp[a][0] * dp[b][0]) % Mod;
        dp[i][1] = (dp[a][0] * dp[b][1] % Mod
                  + dp[a][1] * (dp[b][0] + dp[b][1] + dp[b][A] + dp[b][Ab]) % Mod
                  + dp[a][A] * (dp[b][1] + dp[b][Ab]) % Mod
                  + dp[a][Ab] * (dp[b][1] + dp[b][A]) % Mod) % Mod;
        dp[i][A] = (dp[a][0] * dp[b][A] % Mod + dp[a][A] * dp[b][0] % Mod + dp[a][A] * dp[b][A]) % Mod;
        dp[i][Ab] = (dp[a][0] * dp[b][Ab] % Mod + dp[a][Ab] * dp[b][0] % Mod + dp[a][Ab] * dp[b][Ab]) % Mod;
      }
      if(s[op[i]] == '^') {
        dp[i][0] = (dp[a][0] * dp[b][0] % Mod + dp[a][1] * dp[b][1] % Mod
                  + dp[a][A] * dp[b][A] % Mod + dp[a][Ab] * dp[b][Ab] % Mod) % Mod;
        dp[i][1] = (dp[a][0] * dp[b][1] % Mod + dp[a][1] * dp[b][0] % Mod + dp[a][A] * dp[b][Ab] % Mod + dp[a][Ab] * dp[b][A] % Mod) % Mod;
        dp[i][A] = (dp[a][0] * dp[b][A] % Mod + dp[a][1] * dp[b][Ab] % Mod + dp[a][A] * dp[b][0] % Mod + dp[a][Ab] * dp[b][1] % Mod) % Mod;
        dp[i][Ab] = (dp[a][0] * dp[b][Ab] % Mod + dp[a][1] * dp[b][A] % Mod + dp[a][A] * dp[b][1] % Mod + dp[a][Ab] * dp[b][0] % Mod) % Mod;
      }
    }
  }
  long long tot = 0;
  for(int i = 0 ; i < 4 ; i++)
    tot += dp[0][i];
  tot = myPow(tot % Mod, Mod - 2);
  for(int i = 0 ; i < 4 ; i++) {
    if(i) printf(" ");
    printf("%d", dp[0][i] * tot % Mod);
  }
  printf("\n");
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    solve();
  return 0;
}
