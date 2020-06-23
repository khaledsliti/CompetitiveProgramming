// We only fail when we stop trying
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
typedef __gnu_pbds::tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n, q;
int p[N];

int main()
{
  cin >> n >> q;
  ordered_set st;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    st.insert(p[i]);
  }
  while(q--) {
    char c; cin >> c;
    if(c == '!') {
      int k, x;
      cin >> k >> x;
      --k;
      st.erase(st.find_by_order(st.order_of_key(p[k])));
      p[k] = x;
      st.insert(p[k]);
    } else {
      int a, b;
      cin >> a >> b;
      int ans = st.order_of_key(b + 1) - st.order_of_key(a);
      cout << ans << endl;
    }
  }
  return 0;
}
