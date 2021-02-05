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

const int N = 1e4 + 5;

int n;
int ans[N], seen[N];

int ask(int x, int y) {
  cout << "? " << x + 1 << " " << y + 1 << endl;
  cout.flush();
  int r;
  cin >> r;
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> idx(n);
  iota(all(idx), 0);
  memset(ans, -1, sizeof ans);
  memset(seen, 0, sizeof seen);
  
  while(sz(idx) > 1) {
    vector<int> tmp;
    for(int i = 0; i + 1 < sz(idx); i += 2) {
      int x = idx[i], y = idx[i + 1];
      int xmody = ask(x, y);
      int ymodx = ask(y, x);
      if(xmody > ymodx) {
        ans[x] = xmody;
        tmp.push_back(y);
        seen[xmody] = 1;
      } else {
        ans[y] = ymodx;
        tmp.push_back(x);
        seen[ymodx] = 1;
      }
    }
    if(sz(idx) & 1) {
      tmp.push_back(idx.back());
    }
    idx = tmp;
  }
  
  if(sz(idx) > 0) {
    for(int i = 1; i <= n; i++) {
      if(!seen[i]) {
        for(int j = 0; j < n; j++) {
          if(ans[j] == -1) {
            ans[j] = i;
            break;
          }
        }
        break;
      }
    }
  }

  cout << "!";
  for(int i = 0; i < n; i++) {
    cout << " " << ans[i];
  }
  cout << endl;
  return 0;
}
