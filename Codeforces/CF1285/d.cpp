#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e5 + 5;

struct node{
  int ch[2];
  node(){
    ch[0] = ch[1] = -1;
  }
};

int n;
vector<node> tr;
int dp[N * 32];

void insert(int a)
{
  int cur = 0;
  for(int i = 29 ; i >= 0 ; i--){
    int c = (a >> i) & 1;
    if(tr[cur].ch[c] == -1){
      tr[cur].ch[c] = sz(tr);
      tr.push_back(node());
    }
    cur = tr[cur].ch[c];
  }
}

int solve(int cur, int lev)
{
  int& r = dp[cur];
  if(r != -1) return r;
  r = 0;
  if(tr[cur].ch[0] != -1 && tr[cur].ch[1] != -1){
    r = (1 << lev) | min(solve(tr[cur].ch[0], lev - 1), solve(tr[cur].ch[1], lev - 1));
  }else if(tr[cur].ch[0] != -1)
    r = solve(tr[cur].ch[0], lev - 1);
  else if(tr[cur].ch[1] != -1)
    r = solve(tr[cur].ch[1], lev - 1);
  return r;
}

int main()
{
  scanf("%d", &n);
  tr.pb(node());
  for(int i = 0 ; i < n ; i++){
    int a; scanf("%d", &a);
    insert(a);
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 29) << endl;
  return 0;
}
