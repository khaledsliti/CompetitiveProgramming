#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

string s;
int fib[N];

int main()
{
  fib[0] = fib[1] = 1;
  for(int i = 2 ; i < N ; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  }
  cin >> s;
  int ans = 1;
  for(int i = 0 ; i < sz(s) ; i++) {
    if(s[i] == 'm' || s[i] == 'w')
      return cout << 0 << endl, 0;
    if(s[i] != 'n' && s[i] != 'u')
      continue;
    int j = i;
    while(j < sz(s) && s[j] == s[i])
      j++;
    ans = (1LL * ans * fib[j - i]) % MOD;
    i = j - 1;
  }
  cout << ans << endl;
  return 0;
}
