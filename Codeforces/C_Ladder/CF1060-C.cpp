// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2002;

int n, m;
int a[N], b[N], pref[N * N];
int x;

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  for(int i = 0 ; i < m ; i++)
    cin >> b[i];
  cin >> x;

  vector<pair<int, int>> B;
  for(int i = 0 ; i < m ; i++) {
    int cur = 0;
    for(int j = i ; j < m ; j++) {
      cur += b[j];
      B.push_back({cur, j - i + 1});
    }
  }
  sort(all(B));
  for(int i = 0 ; i < sz(B) ; i++) {
    pref[i] = B[i].second;
    if(i) pref[i] = max(pref[i], pref[i - 1]);
  }

  long long best = 0;
  for(int i = 0 ; i < n ; i++) {
    int cur = 0;
    for(int j = i ; j < n ; j++) {
      cur += a[j];
      int need = x / cur;
      int idx = lower_bound(all(B), make_pair(need + 1, 0)) - B.begin() - 1;
      if(idx >= 0)
        best = max(best, 1LL * (j - i + 1) * pref[idx]);
    }
  }

  cout << best << endl;

  return 0;
}
