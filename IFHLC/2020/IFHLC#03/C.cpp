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

int calc(int i, int j, int n) {
  int ch1 = 0;
  if(j > i) {
    ch1 += j - i - 1;
  } else {
    ch1 += n - i - 1 + j;
  }
  int ch2 = 1;
  if(j <= i) {
    ch2 += i - j;
  } else {
    ch2 += i + (n - j);
  }
  return min(ch1, ch2);
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    int last;
    cin >> last; --last;
    ll ans = 0;
    for(int i = 1; i < k; i++) {
      int cur;
      cin >> cur; cur--;
      ans += calc(last, cur, n);
      last = cur;
    }
    cout << ans << endl;
  }
  return 0;
}
