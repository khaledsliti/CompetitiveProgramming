// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 500006;

int n;
string s;
int bit[26][N];

void add(int *bit, int idx, int val) {
  for(int i = idx ; i <= n ; i += i & -i)
    bit[i] += val;
}

int get(int* bit, int idx) {
  int r = 0;
  for(int i = idx ; i > 0 ; i -= i & -i)
    r += bit[i];
  return r;
}

int get(int* bit, int l, int r) {
  return get(bit, r) - get(bit, l - 1);
}

int main()
{
  cin >> n >> s;
  for(int i = 0 ; i < n ; i++) {
    int cur = s[i] - 'a';
    add(bit[cur], i + 1, 1);
  }
  int q;
  cin >> q;
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int idx;
      char c;
      cin >> idx >> c;
      int cur = s[--idx] - 'a';
      add(bit[cur], idx + 1, -1);
      add(bit[c - 'a'], idx + 1, 1);
      s[idx] = c;
    } else {
      int l, r;
      cin >> l >> r;
      int ans = 0;
      for(int i = 0 ; i < 26 ; i++)
        ans += get(bit[i], l, r) > 0;
      cout << ans << endl;
    }
  }
  return 0;
}
