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

const int N = 3e5 + 5;

int n;
char s[N];
int ans[N];

void solve() {
  scanf("%d%s", &n, s);
  for(int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  int r = 0, l = 0;
  for(int i = 0; i < n; i++) {
    r += s[i] != '<';
    l += s[i] != '>';
    if(s[i] == '-') {
      ans[i] = ans[(i + 1) % n] = 1;
    }
  }
  if(max(r, l) == n) {
    cout << n << endl;
    return;
  }
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += ans[i];
  }
  cout << cnt << endl;
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
