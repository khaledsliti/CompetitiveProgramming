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

const int N = 2e5 + 5;

int n, k;
int t[N], y[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  t[0] = 1;
  for(int i = 1; i <= n; i++) {
    cin >> t[i] >> y[i];
  }
  long long ans = LLONG_MIN;
  multiset<int> neg;
  long long all_sum = 0;
  for(int i = n; i >= 0 && k >= 0; i--) {
    if(t[i] == 1) {
      ans = max(ans, y[i] + all_sum);
      k--;
      if(k >= 0 && sz(neg) > k) {
        int tmp = *neg.rbegin();
        all_sum += tmp;
        neg.erase(neg.find(tmp));
      }
    } else {
      if(y[i] < 0) {
        neg.insert(y[i]);
        if(sz(neg) > k) {
          int tmp = *neg.rbegin();
          all_sum += tmp;
          neg.erase(neg.find(tmp));
        }
      } else {
        all_sum += y[i];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
