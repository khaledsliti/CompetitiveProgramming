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

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  ll ans = 0;
  for(int i = 1; i <= n; i++)
    ans += 1LL * i * (n + 1 - i);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    ans -= 1LL * a * (n + 1 - b);
  }
  cout << ans << endl;
  return 0;
}
