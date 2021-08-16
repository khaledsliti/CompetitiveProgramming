// Guess Who's Back
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

int n;
vector<int> L, R;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    L.push_back(l);
    R.push_back(r);
  }
  sort(all(L));
  sort(all(R));

  long long ans = n;
  for(int i = n - 1; i >= 0; i--) {
    ans += max(L[i], R[i]);
  }
  cout << ans << endl;
  return 0;
}
