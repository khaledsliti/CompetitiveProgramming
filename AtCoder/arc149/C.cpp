// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2004;

int n;
int isp[N * N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for(int i = 2; i < N * N; i++) {
    isp[i] = 1;
  }
  for(int i = 2; i < N * N; i++) {
    if(isp[i]) {
      for(int j = 2 * i; j < N * N; j += i) {
        isp[j] = 0;
      }
    }
  }

  cin >> n;

  int last = 3;
  map<int, vector<int>> a;
  for(int i = 5; i < N * N; i++) {
    if(isp[i]) {
      a[i - last].push_back(last);
      last = i;
    }
  }
  vector<vector<int>> ans(n, vector<int>(n, -1));
  int cur = 2;
  for(int i = 0; i < n && cur <= n * n; i++) {
    for(int j = 0; j < n && cur <= n * n; j++) {
      ans[i][j] = cur;
      cur += 2;
    }
  }
  set<int> rem;
  for(int i = 3; i <= n * n; i += 2) {
    rem.insert(i);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(ans[i][j] != -1) {
        continue;
      }
      vector<int> adj;
      if(i > 0 && ans[i - 1][j] % 2 == 0) {
        adj.push_back(ans[i - 1][j]);
      }
      if(j > 0 && ans[i][j - 1] % 2 == 0) {
        adj.push_back(ans[i][j - 1]);
      }
      if(sz(adj) == 0) {
        goto here;
      }
      int best = -1;
      for(auto& it: a) {
        int cur = it.second.back();
        bool ok = true;
        for(int x: adj) {
          if(isp[x + cur]) {
            ok = false;
          }
        }
        if(ok) {
          best = cur;
          it.second.pop_back();
          break;
        }
      }
      if(best == -1) {
        goto here;
      }
      rem.erase(best);
      ans[i][j] = best;
    }
  }
here:
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      ans[i][j] = *rem.begin();
      rem.erase(rem.begin());
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
