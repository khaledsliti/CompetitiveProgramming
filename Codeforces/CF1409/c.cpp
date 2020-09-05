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

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> sol(n, 1e9);
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int dist = j - i;
      if((y - x) % dist == 0) {
        int diff = (y - x) / dist;
        vector<int> tmp(n);
        tmp[i] = x;
        for(int k = i + 1; k < n; k++) {
          tmp[k] = tmp[k - 1] + diff;
        }
        for(int k = i - 1; k >= 0; k--) {
          tmp[k] = tmp[k + 1] - diff;
        }
        if(tmp[0] > 0 && tmp[n - 1] < sol[n - 1]) {
          for(int i = 0; i < n; i++){
            sol[i] = tmp[i];
          }
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << sol[i] << " ";
  }
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
