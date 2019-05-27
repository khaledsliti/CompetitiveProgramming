#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 3e5 + 6;

int n;
vector<int> pos[N];
int st[N * 4];

void update(int cur, int s, int e, int idx, int add){
  if(idx > e || idx < s)
    return;
  if(s == e){
    st[cur] += add;
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  update(l, s, mid, idx, add);
  update(r, mid + 1, e, idx, add);
  st[cur] = max(st[l], st[r]);
}

int main()
{
  scanf("%d", &n);
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    pos[a].pb(b);
    pos[b].pb(a);
    update(0, 0, N - 1, a, 1);
    update(0, 0, N - 1, b, 1);
  }
  for(int i = 0 ; i < N ; i++)
    if(sz(pos[i]) == n)
      return cout << "YES" << endl, 0;

  for(int i = 1 ; i < N ; i++){
    update(0, 0, N - 1, i, -sz(pos[i]));

    for(int j = 0 ; j < sz(pos[i]) ; j++)
      update(0, 0, N - 1, pos[i][j], -1);

    int rem = n - sz(pos[i]);

    if(st[0] == rem){
      cout << "YES" << endl;
      return 0;
    }

    for(int j = 0 ; j < sz(pos[i]) ; j++)
      update(0, 0, N - 1, pos[i][j], 1);

    update(0, 0, N - 1, i, sz(pos[i]));
  }
  cout << "NO" << endl;
  return 0;
}