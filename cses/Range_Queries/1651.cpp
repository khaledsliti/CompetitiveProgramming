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

const int N = 2e5 + 5;

int n, q;
ll bit[N];

void add(int idx, ll val) {
  for(int i = idx; i < N; i += i & -i)
    bit[i] += val;
}

ll get(int idx) {
  ll r = 0;
  for(int i = idx; i > 0; i -= i & -i)
    r += bit[i];
  return r;
}

int main()
{
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    add(i + 1, a);
    add(i + 2, -a);
  }
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int a, b, c;
      cin >> a >> b >> c;
      add(a, c);
      add(b + 1, -c);
    } else {
      int i;
      cin >> i;
      cout << get(i) << endl;
    }
  }
  return 0;
}
