#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 10;

int n, q, x;
int nxt[N], par[N];

int fs(int x)
{
  return par[x] == x ? x : par[x] = fs(par[x]);
}

int main()
{
  scanf("%d%d", &q, &x);
  for(int i = 0 ; i < x ; i++)
    nxt[i] = i;
  for(int i = 0 ; i < N ; i++)
    par[i] = i;
  while(q--){
    int v;
    scanf("%d", &v);
    int r = v % x;
    if(nxt[r] + 1 < N){
      par[nxt[r]] = fs(nxt[r] + 1);
      nxt[r] += x;
    }
    cout << fs(0) << endl;
  }
  return 0;
}
