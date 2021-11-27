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


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, w;
  cin >> n >> w;
  vector<pair<int, int>> c(n);
  for(int i = 0; i < n; i++) {
    cin >> c[i].first >> c[i].second;
  }
  sort(rall(c));
  long long ans = 0;
  for(int i = 0; i < n && w > 0; i++) {
    int take = min(c[i].second, w);
    ans += c[i].first * 1LL * take;
    w -= take;
  }
  cout << ans << endl;
  return 0;
}
