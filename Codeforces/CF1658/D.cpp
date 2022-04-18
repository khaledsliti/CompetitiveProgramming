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

const int A = 18;
const int N = 1 << A;

int pref[N];

int get(int l, int r) {
  int ans = pref[r];
  if(l > 0) {
    ans ^= pref[l - 1];
  }
  return ans;
}

void solve() {
  int l, r;
  cin >> l >> r;
  vector<int> a(r - l + 1);
  for(int i = 0; i < r - l + 1; i++) {
    cin >> a[i];
  }
  int x = 0;
  for(int b = 0; b < A; b++) {
    int one = 0, zero = 0;
    for(int i = 0; i < sz(a); i++) {
      if(a[i] & (1 << b)) one++;
      else zero++;
    }
    for(int i = l; i <= r; i++) {
      if(i & (1 << b)) one--;
      else zero--;
    }
    assert(abs(one) == abs(zero));
    if(one != 0 && zero != 0)
      x |= (1 << b);
  }
  cout << x << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pref[0] = 0;
  for(int i = 1; i < N; i++) {
    pref[i] = i ^ pref[i - 1];
  }

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
