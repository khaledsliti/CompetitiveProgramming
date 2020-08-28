// We only fail when we stop trying
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef __gnu_pbds::tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const int N = 2e5 + 5;

int n;
long long t;
int a[N];
ordered_set s;

int calc(ll pref) {
  return s.size() - s.order_of_key(pref - t + 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> t;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  s.insert(0);
  ll sum = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    sum += a[i];
    ans += calc(sum);
    s.insert(sum);
  }

  cout << ans << endl;

  return 0;
}
