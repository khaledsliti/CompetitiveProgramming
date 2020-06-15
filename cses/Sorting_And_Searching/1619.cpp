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

const int N = 4e5 + 5;

int n;
vector<pair<int, int>> p;

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    p.push_back({a, 1});
    p.push_back({b, -1});
  }
  sort(all(p));
  int acc = 0;
  int best = 0;
  for(int i = 0; i < sz(p); i++) {
    acc += p[i].second;
    best = max(best, acc);
  }
  cout << best << endl;
  return 0;
}
