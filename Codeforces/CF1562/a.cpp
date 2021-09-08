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

int solve(int a, int b) {
  int j;
  if(b & 1) {
    j = max(a, (b + 1) / 2);
  } else {
    j = max(a, (b + 2) / 2);
  }
  return b % j;
}

int bf(int a, int b) {
  int ans = 0;
  for(int i = a; i <= b; i++) {
    for(int j = i; j <= b; j++) {
      ans = max(ans, j % i);
    }
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    // if(solve(a, b) != bf(a, b))
    //   cout << a << " " << b << " " << solve(a, b) << " " << bf(a, b) << endl;
    // cout << bf(a, b) << endl;
  }
  return 0;
}
