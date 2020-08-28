#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve(int n)
{
  string ans = "";
  while(n > 3)
    ans += '1', n -= 2;
  if(n == 2) ans += '1';
  else ans = '7' + ans;
  cout << ans << endl;
}

int main()
{
  int tests;
  cin >> tests;
  while(tests--){
    int n;
    cin >> n;
    solve(n);
  }
  return 0;
}
