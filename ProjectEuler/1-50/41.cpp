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

bool isPrime(ll x) {
  if(x == 2) return true;
  if(x % 2 == 0) return false;
  for(int i = 3; i * i <= x; i += 2)
    if(x % i == 0)
      return false;
  return true;
}

int main()
{
  vector<ll> pr;
  vector<int> d {1};
  for(int i = 2; i <= 9; i++) {
    d.push_back(i);
    sort(all(d));
    do{
      ll cur = 0;
      for(int i = 0; i < sz(d); i++)
        cur = cur * 10 + d[i];
      if(isPrime(cur)) {
        pr.push_back(cur);
      }
    }while(next_permutation(all(d)));
  }
  sort(all(pr));
  int T;
  cin >> T;
  while(T--) {
    ll n;
    cin >> n;
    int idx = lower_bound(all(pr), n + 1) - begin(pr);
    if(idx == 0) cout << -1 << endl;
    else cout << pr[idx - 1] << endl;
  }
  return 0;
}
