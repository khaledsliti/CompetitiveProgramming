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

const int N = 6e5 + 5;
const int Mod = 998244353;

int n, k;
pair<int, int> arr[N];
int cnt[N];
ll fact[N], inv[N], invFact[N];

ll C(int n, int k) {
  return fact[n] * invFact[k] % Mod * invFact[n - k] % Mod;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  fact[0] = fact[1] = 1;
  inv[1] = 1;
  invFact[0] = invFact[1] = 1;
  for(int i = 2; i < N; i++) {
    fact[i] = fact[i - 1] * i % Mod;
    inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
    invFact[i] = invFact[i - 1] * inv[i] % Mod;
  }

  cin >> n >> k;
  vector<int> pts;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    arr[i].second++;
    pts.push_back(arr[i].first);
    pts.push_back(arr[i].second);
  }
  sort(all(pts));
  pts.resize(unique(all(pts)) - begin(pts));

  map<int, int> str;
  for(int i = 0; i < n; i++) {
    arr[i].first = lower_bound(all(pts), arr[i].first) - begin(pts);
    arr[i].second = lower_bound(all(pts), arr[i].second) - begin(pts);
    cnt[arr[i].first]++;
    cnt[arr[i].second]--;
    str[arr[i].first]++;
  }

  for(int i = 1; i < N; i++) {
    cnt[i] += cnt[i - 1];
  }

  ll ans = 0;
  for(auto st: str) {
    int idx = st.first;
    int fr = st.second;
    int rem = cnt[idx] - fr;
    for(int take = 1; take <= min(fr, k); take++) {
      if(rem + take >= k) {
        ll cur = C(fr, take) * C(rem, k - take) % Mod;
        ans = (ans + cur) % Mod;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
