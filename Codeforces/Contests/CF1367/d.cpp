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

const int N = 55;

int n;
int b[N];
int cnt[26];
int done[N], now[N];
int ans[N];

void solve() {
  string s;
  cin >> s;
  memset(cnt, 0, sizeof cnt);
  for(int i = 0; i < sz(s); i++)
    cnt[s[i] - 'a']++;
  vector<pair<int, int>> av;
  for(int i = 0; i < 26; i++) {
    if(cnt[i] > 0)
      av.push_back({i, cnt[i]});
  }
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    done[i] = now[i] = 0;
  }
  for(int it = 0; it < n; it++) {
    for(int i = 0; i < n; i++)
      now[i] = 0;
    int tot = 0;
    for(int i = 0; i < n; i++) {
      if(!done[i] && !b[i]) {
        now[i] = 1;
        tot++;
      }
    }
    // for(int i = 0; i < n; i++)
    //   cout << now[i] << " ";
    // cout << endl;
    if(!tot) break;
    while(av.back().second < tot) av.pop_back();
    for(int i = 0; i < n; i++)
      if(now[i])
        ans[i] = av.back().first;
    for(int i = 0; i < n; i++)
      if(!now[i] && !done[i]) {
        for(int j = 0; j < n; j++) {
          if(now[j])
            b[i] -= abs(i - j);
        }
      }
    for(int i = 0; i < n; i++)
      if(now[i])
        done[i] = 1;
    av.pop_back();
  }
  // for(int i = 0; i < n; i++)
  //   cout << ans[i] << " ";
  // cout << endl;
  for(int i = 0; i < n; i++)
    cout << char('a' + ans[i]);
  cout << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
