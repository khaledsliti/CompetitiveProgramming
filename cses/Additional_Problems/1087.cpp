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

const int N = 1e6 + 5;

int n;
char s[N];
int nxt[N][4];
int last[N];
string alp = "ACGT";
int dp[N];

int index(char c) {
  for(int i = 0; i < sz(alp); i++)
    if(alp[i] == c)
      return i;
  return -1;
}

int main()
{
  scanf("%s", s);
  n = strlen(s);
  for(int i = 0; i < 4; i++)
    last[i] = n + 1;
  for(int i = n - 1; i >= 0; i--) {
    for(int j = 0; j < 4; j++) {
      nxt[i + 1][j] = last[j];
    }
    last[index(s[i])] = i + 1;
  }
  for(int j = 0; j < 4; j++)
    nxt[0][j] = last[j];
  dp[n + 1] = 0;
  for(int i = n; i >= 0; i--) {
    dp[i] = n + 5;
    for(int j = 0; j < 4; j++)
      dp[i] = min(dp[i], 1 + dp[nxt[i][j]]);
  }
  for(int cur = 0; cur <= n; ) {
    for(int j = 0; j < 4; j++) {
      if(dp[cur] == 1 + dp[nxt[cur][j]]) {
        printf("%c", alp[j]);
        cur = nxt[cur][j];
        break;
      }
    }
  }
  printf("\n");
  return 0;
}
