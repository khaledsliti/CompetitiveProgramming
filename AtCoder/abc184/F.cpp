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

const int N = 41;

int n, T;
vector<int> a, b;

void fun(const vector<int>& a, vector<ll>& b) {
  for(int msk = 0; msk < (1 << sz(a)); msk++) {
    ll s = 0;
    for(int i = 0; i < sz(a); i++) {
      if(msk & (1 << i)) {
        s += a[i];
      }
    }
    b.pb(s);
  }
}

int main()
{
  cin >> n >> T;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(i < 20) a.pb(x);
    else b.pb(x);
  }
  vector<ll> subA, subB;
  fun(a, subA);
  fun(b, subB);
  sort(all(subB));
  ll best = 0;
  for(int i = 0; i < sz(subA); i++) {
    ll need = T - subA[i];
    if(need < 0) continue;
    int idx = lower_bound(all(subB), need + 1) - begin(subB);
    if(idx > 0) {
      idx--;
      best = max(best, subA[i] + subB[idx]);
    }
  }
  cout << best << endl;
  return 0;
}
