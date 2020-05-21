// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const long long Max = 1e18;

vector<long long> val;

bool isSqr(long long x) {
  long long v = sqrt(x);
  return v * v == x;
}

long long calc(long long r) {
  return lower_bound(all(val), r + 1) - begin(val);
}

long long calc(long long l, long long r) {
  long long res = calc(r) - calc(l - 1);
  long long x = ceil(sqrt(l));
  long long y = sqrt(r);
  res += y - x + 1;
  return res;
}

int main()
{
  for(long long x = 2 ; x <= 1000001 ; x++) {
    long long cur = x * x * x;
    while(true) {
      if(!isSqr(cur))
        val.push_back(cur);
      if(cur > Max / x) break;
      cur *= x;
    }
  }
  sort(all(val));
  val.resize(unique(all(val)) - begin(val));
  int q;
  scanf("%d", &q);
  while(q--) {
    long long l, r;
    scanf("%I64d%I64d", &l, &r);
    printf("%I64d\n", calc(l, r));
  }
  return 0;
}
