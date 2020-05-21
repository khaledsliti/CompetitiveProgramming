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

ll tp[19], mem[19];

// O(log(r)^2)
int solve(ll idx) {
  ll len = -1;
  for(int i = 1; i <= 18; i++) {
    if(mem[i] >= idx) {
      len = i;
      break;
    }
  }
  assert(len > 0);
  ll digits = idx - mem[len - 1] - 1;
  ll At = tp[len - 1] + digits / len;
  ll rem = digits % len;
  string res;
  while(At > 0) {
    res += char('0' + At % 10);
    At /= 10;
  }
  reverse(all(res));
  return res[rem] - '0';
}

int main()
{
  tp[0] = 1;
  mem[0] = 0;
  for(int i = 1; i < 18; i++) {
    tp[i] = 10 * tp[i - 1];
    mem[i] = i - 1;
    for(int j = 0; j < i - 1; j++)
      mem[i] = mem[i] * 10 + 8;
    mem[i] = mem[i] * 10 + 9;
  }
  int T;
  cin >> T;
  while(T--) {
    int ans = 1;
    for(int i = 0; i < 7; i++) {
      ll idx;
      cin >> idx;
      ans *= solve(idx);
    }
    cout << ans << endl;
  }
  return 0;
}
