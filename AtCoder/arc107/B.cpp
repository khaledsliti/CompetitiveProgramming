// RedStone
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

ll calc(int sum, int n) {
  int left = max(1, sum - n), right = min(n, sum - 1);
  if(left > right) return 0;
  return right - left + 1;
}

int main()
{
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  for(int left = 2; left <= 2 * n; left++) {
    int right = left - k;
    if(right >= 2 && right <= 2 * n) {
      ans += calc(left, n) * calc(right, n);
    }
  }
  cout << ans << endl;
  return 0;
}
