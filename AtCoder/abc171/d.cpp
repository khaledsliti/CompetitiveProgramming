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

int n, q;
int fr[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    fr[a]++;
  }
  ll ans = 0;
  for(int i = 0; i < N; i++)
    ans += 1LL * fr[i] * i;
  cin >> q;

  while(q--) {
    int b, c;
    cin >> b >> c;
    ans -= 1LL * fr[b] * b;
    ans += 1LL * fr[b] * c;
    fr[c] += fr[b];
    fr[b] = 0;
    cout << ans << endl;
  }
  return 0;
}
