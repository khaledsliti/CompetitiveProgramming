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

const int N = 20;

vector<int> a, b;
vector<ll> A, B;

int main()
{
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(i < 20) a.push_back(x);
    else b.push_back(x);
  }
  for(int msk = 0; msk < (1 << sz(a)); msk++) {
    ll sum = 0;
    for(int i = 0; i < sz(a); i++) {
      if(msk & (1 << i))
        sum += a[i];
    }
    A.push_back(sum);
  }
  for(int msk = 0; msk < (1 << sz(b)); msk++) {
    ll sum = 0;
    for(int i = 0; i < sz(b); i++) {
      if(msk & (1 << i))
        sum += b[i];
    }
    B.push_back(sum);
  }
  sort(all(B));
  long long ans = 0;
  for(int i = 0; i < sz(A); i++) {
    ll need = x - A[i];
    if(need <= 0) {
      ans += need == 0;
      continue;
    }
    ans += lower_bound(all(B), need + 1) - lower_bound(all(B), need);
  }
  cout << ans << endl;
  return 0;
}
