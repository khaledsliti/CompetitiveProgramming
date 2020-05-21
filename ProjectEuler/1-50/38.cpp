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

const int N = 100001;

int n, k;

void print(int msk) {
  for(int i = 0; i < k; i++)
    cout << ((msk >> i) & 1);
  cout << endl;
}

bool check(int num) {
  int msk = 0;
  ll prod = 1;
  for(int x = 1; ; x++) {
    int cur = num * x;
    int cur_msk = 0;
    while(cur > 0) {
      int d = cur % 10;
      if(!d) return false;
      --d;
      if(cur_msk & (1 << d))
        return false;
      cur_msk |= (1 << d);
      cur /= 10;
    }
    if(msk & cur_msk)
      return false;
    msk |= cur_msk;
    if(x > 1 && msk == (1 << k) - 1) {
      return true;
    }
  }
  return false;
}

int main()
{
  cin >> n >> k;
  for(int i = 2; i < n; i++) {
    if(check(i)) {
      cout << i << endl;
    }
  }
  return 0;
}
