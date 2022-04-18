// RedStone
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

const int N = 1e5 + 5;

int n, m;
struct Ed {
  int a, b, c;
};
vector<Ed> e;
int par[30][N];
int dele[N];

int init(int b) {
  for(int i = 0; i < n; i++) {
    par[b][i] = i;
  }
}

int fs(int b, int a) {
  return par[b][a] == a ? a : par[b][a] = fs(b, par[b][a]);
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m ;i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    e.push_back({a, b, c});
  }

  for(int i = 0; i < 30; i++) {
    init(i);
    for(int j = 0; j < m; j++) {
      auto cur = e[j];
      int a = cur.a, b = cur.b, c = cur.c;
      if(!dele[j] && !(c & (1 << i))) {
        dele[j] = 1;
      }
    }
    for(int j = 0; j < m; j++) {
      if(!dele[j]) {
        auto cur = e[j];
        int a = cur.a, b = cur.b;
        a = fs(i, a), b = fs(i, b);
        if(a != b) {
          par[i][a] = b;
        }
      }
    }
  }

  int q;
  cin >> q;
  while(q--) {
    int a, b;
    cin >> a >> b; --a, --b;
    int ans = 0;
    for(int i = 1; i < 30; i++) {
      if(fs(i, a) == fs(i, b)) {
        ans |= (1 << (i - 1));
      }
    }
    cout << ans << endl;
  }

  return 0;
}
