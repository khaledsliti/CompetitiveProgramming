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

int n;
int p[20];

int main()
{
  cin >> n;
  ll s = 0;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    s += p[i];
  }
  ll best = s;
  for(int msk = 0; msk < (1 << n); msk++) {
    ll cur = 0;
    for(int i = 0; i < n; i++)
      if(msk & (1 << i))
        cur += p[i];
    best = min(best, abs(s - cur - cur));
  }
  cout << best << endl;
  return 0;
}
