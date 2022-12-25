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

const int A = 26;
const int N = 1e5 + 5;

int n;
string s;
int out[A], in[A];

void solve() {
  cin >> n >> s;
  memset(out, -1, A * sizeof(out[0]));
  memset(in, 0, A * sizeof(in[0]));
  string ans = "";
  int e = 0;
  for(int i = 0; i < n; i++) {
    int cur = s[i] - 'a';
    if(out[cur] == -1) {
      e++;
      for(int c = 0; c < A; c++) {
        if(c == cur || in[c]) continue;
        int t = c;
        while(out[t] != -1) {
          t = out[t];
        }
        if(e < 26 && t == cur) continue;
        in[c] = 1;
        out[cur] = c;
        break;
      }
    }
    ans += char('a' + out[cur]);
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
