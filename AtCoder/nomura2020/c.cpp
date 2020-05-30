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

const int N = 1e5 + 5;

int n;
int a[N];
ll mx[N];

int main()
{
  cin >> n;
  for(int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  if(n == 0) {
    if(a[0] == 1) cout << 1 << endl;
    else cout << -1 << endl;
    return 0;
  }
  if(a[0]) return cout << -1 << endl, 0;
  mx[n] = a[n];
  for(int i = n - 1; i >= 0; i--) {
    mx[i] = a[i] + mx[i + 1];
  }
  for(int i = 0; i <= n; i++) {
    if((1LL << i) > mx[i])  break;
    else mx[i] = (1LL << i);
  }
  ll ans = mx[n];
  for(int i = 0; i < n; i++) {
    mx[i + 1] = min(mx[i + 1], (mx[i] - a[i]) * 2);
  }
  for(int i = 0; i <= n; i++)
    if(mx[i] < a[i]) {
      cout << -1 << endl;
      return 0;
    }
  for(int i = 0; i < n; i++)
    if(mx[i] == a[i]) {
      cout << -1 << endl;
      return 0;
    }
  for(int i = 0; i < n; i++) {
    ans += mx[i];
  }
  cout << ans << endl;
  return 0;
}
