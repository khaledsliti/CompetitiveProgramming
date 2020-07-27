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

const int N = 51;

int n;
int g[N][N], in[N], out[N];

int main()
{
  ios::sync_with_stdio(false);
  int T, tc = 1;
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++)
        g[i][j] = 0;
      g[i][i] = 1;
      in[i] = out[i] = 0;
    }
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
      if(s[i] == 'Y') in[i] = 1;
    cin >> s;
    for(int i = 0; i < n; i++)
      if(s[i] == 'Y') out[i] = 1;
    for(int i = 0; i < n - 1; i++) {
      if(out[i] && in[i + 1])
        g[i][i + 1] = 1;
      if(in[i] && out[i + 1])
        g[i + 1][i] = 1;
    }
    for(int k = 0; k < n; k++) {
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
          g[i][j] |= g[i][k] & g[k][j];
        }
    }
    printf("Case #%d:\n", tc++);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(g[i][j]) printf("Y");
        else printf("N");
      }
      printf("\n");
    }
  }
  return 0;
}
