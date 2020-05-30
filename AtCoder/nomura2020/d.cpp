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

const int N = 5001;

int n;
int p[N];
int par[N];
vector<int> comp, cnt;

int fs(int x) {
  return par[x] == x ? x : par[x] = fs(par[x]);
}

int solve() {
  n = sz(comp);
  int mn = 0;
  for(int i = 0; i < n; i++)
    mn += comp[i] - 1;
  int mx = mn + n - 1;
  int ans = 0;
  for(int cur = mn; cur <= mx; cur++) {
    
  }
  return ans;
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    if(~p[i]) {
      int a = fs(i);
      int b = fs(p[i]);
      if(a != b)
        par[a] = b;
    }
  }
  for(int i = 0; i < n; i++) {
    if(fs(i) == i) {
      comp.push_back(0), cnt.push_back(0);
      for(int j = 0; j < n; j++) {
        if(fs(j) == i) {
          comp.back()++;
          if(p[j] == -1)
            cnt.back()++;
        }
      }
    }
  }
  cout << solve() << endl;
  return 0;
}
