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

const int N = 501;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> sol;
  sol.pb({0, 0});
  int x = 1, y = 1;
  for(int i = 0; i <= n; i++) {
    sol.push_back({x, y});
    sol.push_back({x - 1, y});
    sol.push_back({x, y - 1});
    x += 1, y += 1;
  }
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++)
    cout << sol[i].first << " " << sol[i].second << endl;
  return 0;
}
