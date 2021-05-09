// Guess Who's Back
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

const int N = 3000007;

ll n, k;
ll sum[N];
ll acc[N], diff[N];

void build() {
  ll s = 3 * n;
  ll i = 0, cur;
  for(cur = 2; cur <= n; cur++, i++) {
    diff[i] = cur;
  }
  cur -= 3;
  while(cur >= 0) {
    diff[i++] = cur;
    cur -= 2;
  }
  int j = i--;
  if(n % 2 == 0) j--;
  while(i >= 0) {
    diff[j++] = -diff[i--];
  }
  
  assert(j < N);

  for(ll cur = 1, i = 3; i <= 3 * n; i++) {
    acc[i] = cur;
    cur += diff[i - 3];
  }
}

ll ways(ll s) {
  ll f = max(1LL, s - n);
  ll last = min(1LL * n, s - 1);
  return last - f + 1;
}

int main()
{
  cin >> n >> k;

  build();

  ll v = 0;
  for(int i = 3; i <= 3 * n; i++) {
    v += acc[i];
  }

  assert(v == n * n * n);

  ll num = k, sum;
  for(int i = 3; i <= 3 * n; i++) {
    if(num > acc[i]) num -= acc[i];
    else {
      sum = i;
      break;
    }
  }

  for(int i = 1; i <= n; i++) {
    ll rem = sum - i;
    if(rem > 2 * n) continue;
    ll w = ways(rem);
    if(w >= num) {
      ll f = max(1LL, rem - n) + num - 1;
      cout << i << " " << f << " " << sum - f - i << endl;
      break;
    } else {
      num -= w;
    }
  }

  return 0;
}
