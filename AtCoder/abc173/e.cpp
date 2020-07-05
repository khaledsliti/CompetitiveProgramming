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

const int N = 2e5 + 5;
const int Mod = 1e9 + 7;

int n, k;
vector<ll> pos, neg;

void take(ll& ans, vector<ll>& v) {
  k--;
  ans = (ans * v.back()) % Mod;
  v.pop_back();
}

ll solvePositive() {
  reverse(all(neg));
  ll ans = 1;
  while(k > 0) {
    if(k == 1) {
      take(ans, pos);
    } else {
      if(sz(neg) < 2) {
        take(ans, pos);
      } else if(sz(pos) < 2) {
        take(ans, neg);
        take(ans, neg);
      } else {
        ll ch1 = pos[sz(pos) - 1] * pos[sz(pos) - 2];
        ll ch2 = neg[sz(neg) - 1] * neg[sz(neg) - 2];
        if(ch1 >= ch2) {
          take(ans, pos);
        } else {
          take(ans, neg);
          take(ans, neg);
        }
      }
    }
  }
  ans = (ans % Mod + Mod) % Mod;
  return ans;
}

ll solveNegative() {
  reverse(all(pos));
  ll ans = 1;
  take(ans, neg);
  while(k > 0) {
    if(k == 1) {
      take(ans, pos);
    } else {
      if(sz(neg) < 2) {
        take(ans, pos);
      } else if(sz(pos) < 2) {
        take(ans, neg);
        take(ans, neg);
      } else {
        ll ch1 = pos[sz(pos) - 1] * pos[sz(pos) - 2];
        ll ch2 = neg[sz(neg) - 1] * neg[sz(neg) - 2];
        if(ch1 <= ch2) {
          take(ans, pos);
        } else {
          take(ans, neg);
          take(ans, neg);
        }
      }
    }
  }
  ans = (ans % Mod + Mod) % Mod;
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(a >= 0) pos.push_back(a);
    else neg.push_back(a);
  }
  sort(all(pos));
  sort(all(neg));
  bool canPositive = false;
  for(int i = 0; i <= min(sz(neg), k); i += 2)
    if(k - i <= sz(pos))
      canPositive = true;
  if(canPositive) cout << solvePositive() << endl;
  else cout << solveNegative() << endl;
  return 0;
}
