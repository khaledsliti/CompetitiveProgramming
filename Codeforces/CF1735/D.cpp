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

const int K = 20;
const int N = 1e3 + 5;

int n, k;
vector<int> a[N];
ll h[N];
map<ll, int> idx;
ll cnt[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    a[i].resize(k);
    h[i] = 0;
    for(int j = 0; j < k; j++) {
      cin >> a[i][j];
      h[i] = h[i] * 3 + a[i][j];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      ll cur_h = 0;
      for(int l = 0; l < k; l++){
        int c;
        if(a[i][l] == a[j][l]) {
          c = a[i][l];
        } else {
          c = 3 - a[i][l] - a[j][l];
        }
        cur_h = cur_h * 3 + c;
      }
      if(idx.count(cur_h)) {
        cnt[i]++;
        cnt[j]++;
        cnt[idx[cur_h]]++;
      }
    }
    idx[h[i]] = i;
  }

  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}
