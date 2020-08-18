// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2002;

int n, k;
int cnt[26];
int vis[N];

void solve() {
  cin >> n >> k;
  memset(cnt, 0, sizeof cnt);
  for(int i = 0; i < n; i++) {
    char c; cin >> c;
    cnt[c - 'a']++;
  }
  int best = 1;
  for(int len = 2; len <= n; len++) {
    for(int i = 0; i < len; i++)
      vis[i] = 0;
    int num = 0, val = 0;
    for(int i = 0; i < len; i++) {
      if(vis[i]) break;
      int j = i;
      int tot = 0;
      while(!vis[j]) {
        vis[j] = 1;
        j = (j + k) % len;
        tot++;
      }
      val = tot;
      num++;
    }
    int have = 0;
    for(int i = 0; i < 26; i++)
      have += cnt[i] / val;
    if(have >= num) {
      best = max(best, len);
    }
  }
  cout << best << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
