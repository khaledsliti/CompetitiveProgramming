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

long long getNxt(long long n, long long i) {
  long long l = i, h = n, last = i;
  while(l <= h) {
    long long mid = (l + h) >> 1;
    if(n / i == n / mid) {
      last = mid;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  return last + 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long N;
  cin >> N;

  long long cur = 1;
  long long ans = 0;

  while(cur <= N) {
    auto nxt = getNxt(N, cur);
    ans += (nxt - cur) * (N / cur);
    cur = nxt;
  }

  cout << ans << endl;
  
  return 0;
}
