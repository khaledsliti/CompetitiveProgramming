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

const int N = 2e5 + 5;

int n;
int a[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans += abs(a[n / 2] - a[i]);
  }
  cout << ans << endl;
  return 0;
}
