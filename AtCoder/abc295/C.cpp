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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  map<int, int> fr;
  for(int i = 0; i < n; i++) {
    int c; cin >> c;
    fr[c]++;
  }
  int ans = 0;
  for (auto x: fr) {
    ans += x.second / 2;
  }
  cout << ans << endl;
  return 0;
}
