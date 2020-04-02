// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int V = 1e6 + 1;

int n, q;
long long tot = 0;
long long bit[2][N], bit2[2][N];
int last_r[N], last_c[N];
int vr[N], vc[N];

void add(long long* bit, int idx,int val) {
  for(; idx < N ; idx += idx&-idx)
    bit[idx] += val;
}

long long query(long long* bit, int idx) {
  long long sum = 0;
  for(; idx > 0 ; idx -= idx&-idx)
    sum += bit[idx];
  return sum;
}

long long query(long long *bit, int a, int b) {
  if(a > b) return 0;
  return query(bit, b) - query(bit, a - 1);
}

int main()
{
  scanf("%d%d", &n, &q);

  for(int i = 1 ; i <= q ; i++) {
    int t; scanf("%d", &t);
    if(t == 1) { // row
      int r, v;
      scanf("%d%d", &r, &v); --r;
      tot += 1LL * n * v - query(bit[1], last_r[r] + 1, i - 1);
      tot -= 1LL * vr[r] * (n - query(bit2[1], last_r[r] + 1, i - 1));
      if(last_r[r] > 0) add(bit[0], last_r[r], -vr[r]), add(bit2[0], last_r[r], -1);
      add(bit[0], i, v);
      add(bit2[0], i, 1);
      last_r[r] = i;
      vr[r] = v;
    } else { // col
      int c, v;
      scanf("%d%d", &c, &v); --c;
      tot += 1LL * n * v - query(bit[0], last_c[c] + 1, i - 1);
      tot -= 1LL * vc[c] * (n - query(bit2[0], last_c[c] + 1, i - 1));
      if(last_c[c] > 0) add(bit[1], last_c[c], -vc[c]), add(bit2[1], last_c[c], -1);
      add(bit[1], i, v);
      add(bit2[1], i, 1);
      last_c[c] = i;
      vc[c] = v;
    }
    printf("%I64d\n", tot);
  }
  return 0;
}
