// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long n;

bool check(long long k)
{
  long long have = n;
  long long eat = 0;
  while(have > 0) {
    long long mn = min(have, k);
    have -= mn;
    eat += mn;
    have -= have / 10;
  }
  return eat * 2 >= n;
}

int main()
{
  cin >> n;
  long long l = 1, r = n, ans = n;
  while(l <= r) {
    long long mid = (l + r) >> 1;
    if(check(mid)){
      ans = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
