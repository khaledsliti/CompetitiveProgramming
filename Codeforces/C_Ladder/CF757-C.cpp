// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1000004;
const int Mod = 1e9 + 7;

int n, m;
vector<pair<int, int>> col[N];
int fact[N];

int main()
{
  fact[0] = 1;
  for(int i = 1 ; i < N ; i++) {
    fact[i] = 1LL * fact[i - 1] * i % Mod;
  }
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < n ; i++) {
    int g; scanf("%d", &g);
    map<int, int> cnt;
    for(int j = 0 ; j < g ; j++) {
      int a; scanf("%d", &a);
      cnt[--a]++;
    }
    for(auto p : cnt) {
      col[p.first].pb({i, p.second});
    }
  }
  sort(col, col + m);
  int ans = 1;
  for(int i = 0 ; i < m ; i++) {
    int j = i + 1;
    while(j < m && col[i] == col[j])
      j++;
    ans = (ans * 1LL * fact[j - i]) % Mod;
    i = j - 1;
  }
  cout << ans << endl;
  return 0;
}
