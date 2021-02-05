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

const int N = 27;

int g[N][N];
string ans;

void dfs(int cur) {
  for(int nxt = 0; nxt <= 26; nxt++) {
    if(nxt == cur) continue;
    while(g[cur][nxt] > 0) {
      g[cur][nxt]--;
      dfs(nxt);
    }
  }
  while(g[cur][cur]) {
    g[cur][cur]--;
    dfs(cur);
  }
  if(cur) {
    ans += char('a' + cur - 1);
  }
}

void check(string s) {
  s += '#';
  set<string> a;
  for(int i = 0; i < sz(s); i++) {
    string t = s.substr(1) + s[0];
    a.insert(t);
    s = t;
  }
  for(auto x: a) cout << x << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s, t;
  cin >> s;
  t = s;
  sort(all(t));
  for(int i = 0; i < sz(s); i++) {
    int a = max(0, t[i] - 'a' + 1);
    int b = max(0, s[i] - 'a' + 1);
    g[b][a]++;
  }
  dfs(0);
  reverse(all(ans));
  cout << ans << endl;
  return 0;
}
