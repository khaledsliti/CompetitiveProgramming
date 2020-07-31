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

const int N = 5007;
const int A = 26;
const int Mod = 1e9 + 7;

struct Node {
  int nxt[A];
  int w;
  Node() {
    w = 0;
    memset(nxt, -1, sizeof nxt);
  }
};

int n;
char s[N], p[N * N];
vector<Node> tr;
int dp[N];

void insert(char *s) {
  int cur = 0;
  for(int i = 0; s[i]; i++) {
    int c = s[i] - 'a';
    if(tr[cur].nxt[c] == -1) {
      tr[cur].nxt[c] = sz(tr);
      tr.push_back(Node());
    }
    cur = tr[cur].nxt[c];
  }
  tr[cur].w++;
}

int solve(int i) {
  if(i >= n) return 1;
  int& r = dp[i];
  if(r != -1) return r;
  r = 0;
  int cur = 0;
  for(int j = i; j < n; j++) {
    int c = s[j] - 'a';
    if(tr[cur].nxt[c] == -1)
      break;
    cur = tr[cur].nxt[c];
    if(tr[cur].w)
      r = (r + solve(j + 1)) % Mod;
  }
  return r;
}

int main()
{
  scanf("%s", s);
  n = strlen(s);
  int q;
  tr.push_back(Node());
  scanf("%d", &q);
  while(q--) {
    scanf("%s", p);
    insert(p);
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0) << endl;
  return 0;
}
