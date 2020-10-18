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

const int N = 2e5 + 5;

int n;
char s[N];

void solve() {
  scanf("%s", s);
  n = strlen(s);
  int cnt = 0, ans = n;
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == 'B') cnt++;
    if(s[i] == 'A') {
      if(cnt > 0) {
        ans -= 2;
        cnt--;
      }
    }
  }
  ans -= cnt / 2 * 2;
  printf("%d\n", ans);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
