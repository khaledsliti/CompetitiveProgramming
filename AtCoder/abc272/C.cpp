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

const int N = 1e5 + 5;

int n;
vector<int> even, odd;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    if(a & 1) {
      odd.push_back(a);
    } else {
      even.push_back(a);
    }
  }
  sort(rall(even));
  sort(rall(odd));
  int ans = -1;
  if(sz(even) >= 2) {
    ans = max(ans, even[0] + even[1]);
  }
  if (sz(odd) >= 2) {
    ans = max(ans, odd[0] + odd[1]);
  }
  cout << ans << endl;
  return 0;
}
