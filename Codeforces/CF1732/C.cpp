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

const int L = 30;
const int N = 1e5 + 5;

int n, q;
int a[N];
long long pref[N];
int x[N];

long long f(int i, int j) {
  return pref[j] - (i > 0 ? pref[i - 1] : 0) - (x[j] ^ (i > 0 ? x[i - 1] : 0));
}

void maxi(int& ans_l, int& ans_r, ll& ans, int l, int r) {
  long long cur = f(l, r);
  if(cur > ans || cur == ans && (r - l < ans_r - ans_l || r - l == ans_r - ans_l && l < ans_l)) {
    ans = cur;
    ans_l = l;
    ans_r = r;
  }
}

pair<int, int> bf() {
  int ans_l = 0, ans_r = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      int cur = f(i, j);
      if(cur > ans || cur == ans && (j - i < ans_r - ans_l || j - i == ans_r - ans_l && i < ans_l)) {
        ans = cur;
        ans_l = i;
        ans_r = j;
      }
    }
  }
  return {ans_l, ans_r};
}

void gen() {
  n = rand() % 7 + 1;
  for(int i = 0; i < n; i++) {
    a[i] = rand() % 30;
  }
}

void solve() {
  gen();
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    pref[i] = a[i];
    x[i] = a[i];
    if(i > 0) {
      pref[i] += pref[i - 1];
      x[i] ^= x[i - 1];
    }
  }
  
  while(q--) {
    int l, r; cin >> l >> r;
    --l, --r;
    // int ans_l = l, ans_r = l;
    // long long ans = 0;
    // if(l < r) {
    //   maxi(ans_l, ans_r, ans, l, r);
    //   maxi(ans_l, ans_r, ans, l, r - 1);
    //   maxi(ans_l, ans_r, ans, l - 1, r);
    // }
    // cout << ans_l + 1 << " " << ans_r + 1 << endl;
  }
  // for(int b = L - 1; b >= 0; b--) {
  //   vector<int> pos;
  //   for(int i = 0; i < n; i++) {
  //     if(a[i] & (1 << b)) {
  //       pos.push_back(i);
  //     }
  //   }
  //   if(!sz(pos)) continue;
  //   maxi(ans_l, ans_r, ans, pos[0], pos[sz(pos) - 1]);
  //   if(sz(pos) > 1) {
  //     maxi(ans_l, ans_r, ans, pos[1], pos[sz(pos) - 1]);
  //     maxi(ans_l, ans_r, ans, pos[0], pos[sz(pos) - 2]);
  //   }
  // }
  // auto cr = bf();
  // auto want = f(cr.first, cr.second);

  // for(int i = 0; i < n; i++) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

  // for(int i = 0; i < n; i++) {
  //   cout << bitset<8>(a[i]) << " ";
  // }
  // cout << endl;

  // if(ans != want) {
  //   cout << cr.first << " " << cr.second << " = " << want << endl;
  //   cout << ans_l << " " << ans_r << " = " << ans << endl;
  //   exit(0);
  // }
  // cout << "Correct " << cr.first << " " << cr.second << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
 