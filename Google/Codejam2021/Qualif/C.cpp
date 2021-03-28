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

int n, c;
int a[10000];

void solve(int l, int r, int c, int d, int cur) {
  if(l > r) return;
  if(l == r) {
    a[l] = cur;
    return;
  }
  int w = r - l;
  if(d) {
    if(c > w) {
      a[r] = cur;
      solve(l, r - 1, c - w, !d, cur + 1);
    } else {
      int idx = l + c;
      a[idx] = cur++;
      for(int i = idx - 1; i >= l; i--) {
        a[i] = cur++;
      }
      for(int i = idx + 1; i <= r; i++) {
        a[i] = cur++;
      }
    }
  } else {
    if(c > w) {
      a[l] = cur;
      solve(l + 1, r, c - w, !d, cur + 1);
    } else {
      int idx = r - c;
      a[idx] = cur++;
      for(int i = idx + 1; i <= r; i++) {
        a[i] = cur++;
      }
      for(int i = idx - 1; i >= l; i--) {
        a[i] = cur++;
      }
    }
  }
}

void solve(int& tc) {
  cout << "Case #" << tc++ << ": ";
  cin >> n >> c;

  if(c < n - 1 || c > n * (n + 1) / 2 - 1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  
  c -= n - 1;
  
  solve(0, n - 1, c, 1, 1);

  for(int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--) {
    solve(tc);
  }
  return 0;
}
