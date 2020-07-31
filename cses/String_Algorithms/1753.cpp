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

const int N = 1e6 + 4;

int n, m;
char s[N], p[N];
int f[N];

int main()
{
  scanf("%s%s", s, p);
  n = strlen(s);
  m = strlen(p);
  f[0] = 0;
  for(int i = 1, k = 0; i < m; i++) {
    while(k > 0 && p[i] != p[k]) k = f[k - 1];
    if(p[i] == p[k]) k++;
    f[i] = k;
  }
  int ans = 0;
  for(int i = 0, k = 0; i < n; i++) {
    while(k > 0 && s[i] != p[k]) k = f[k - 1];
    if(s[i] == p[k]) k++;
    if(k == m) ans++, k = f[k - 1];
  }
  cout << ans << endl;
  return 0;
}
