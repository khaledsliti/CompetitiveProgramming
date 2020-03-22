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

int n, q;
int A[N];
long long acc[N], z[N];

int get_left(int x, int last) {
  return lower_bound(A, A + last + 1, 2 * x - A[last]) - A;
}

bool check(int x, int r, int& nA) {
  int l = get_left(x, r - 1);
  D(l); D(r);
  nA = r - l;
  int nT = n - 1 - r;
  return nA <= nT;
}

long long get_acc(int l, int r) {
  return acc[r] - (l > 0 ? acc[l - 1] : 0);
}

long long solve(int x) {
  int st = lower_bound(A, A + n, x + 1) - A;
  if(st >= n - 1) return z[n - 1];
  if(st <= 0) return get_acc(n / 2, n - 1);
  int cur_nA = -1;
  check(x, 1, cur_nA);
  return 0;

  int l = st, r = n - 1, last = n - 1, nA = 0;
  while(l <= r) {
    int mid = (l + r) / 2;
    int cur_nA;
    if(check(x, mid, cur_nA)) {
      last = mid;
      nA = cur_nA;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  D(last);
  long long best = get_acc(last, n - 1);
  int nT = n - last + 1;
  if(nA < nT) nA++;
  if(last - nA >= 0) best += z[last - nA];
  return best;
}

int main()
{
  scanf("%d%d", &n, &q);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", &A[i]);
    acc[i] = (i > 0 ? acc[i - 1] : 0) + A[i];
    z[i] = A[i];
    if(i - 2 >= 0) z[i] += z[i - 2];
  }
  while(q--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", solve(x));
  }
  return 0;
}
