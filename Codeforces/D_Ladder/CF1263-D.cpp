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

const int N = 2e5 + 5;

int n;
int par[N];
vector<int> s[N];

int fs(int x) { return x == par[x] ? x : par[x] = fs(par[x]); }

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    string str;
    cin >> str;
    sort(all(str));
    str.resize(unique(all(str)) - begin(str));
    for(int j = 0; j < sz(str); j++)
      s[str[j] - 'a'].push_back(i);
  }
  for(int i = 0; i < n; i++)
    par[i] = i;
  for(int i = 0; i < 26; i++)
    for(int j = 1; j < sz(s[i]); j++) {
      int a = fs(s[i][0]);
      int b = fs(s[i][j]);
      if(a != b)
        par[a] = b;
    }
  int ans = 0;
  for(int i = 0; i < n; i++)
    ans += fs(i) == i;
  cout << ans << endl;
  return 0;
}
