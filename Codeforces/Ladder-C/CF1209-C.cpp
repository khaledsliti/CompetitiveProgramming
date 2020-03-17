// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
char s[N];
int ans[N];

bool solve(int d) {
  for(int i = 0 ; i < n ; i++) {
    int cur = s[i] - '0';
    if(cur < d) ans[i] = 1;
    else if(cur > d) ans[i] = 2;
    else ans[i] = 0;
  }
  for(int i = 0 ; i < n && ans[i] != 2 ; i++)
    if(ans[i] == 0)
      ans[i] = 2;
  for(int i = n - 1 ; i >= 0 && ans[i] != 1 ; i--)
    if(ans[i] == 0)
      ans[i] = 1;
  int last_1 = -1, last_2 = -1;
  for(int i = 0 ; i < n ; i++) {
    int cur = s[i] - '0';
    if(!ans[i])
      return false;
    if(ans[i] == 1) {
      if(cur < last_1)
        return false;
      last_1 = cur;
    }
    if(ans[i] == 2) {
      if(cur < last_2)
        return false;
      last_2 = cur;
    }
  }
  return true;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    scanf("%d", &n);
    scanf("%s", s);
    bool yes = false;
    for(int d = 0 ; !yes && d < 10 ; d++) {
      yes = solve(d);
    }
    if(!yes)
      puts("-");
    else {
      for(int i = 0 ; i < n ; i++)
        printf("%d", ans[i]);
      puts("");
    }
  }
  return 0;
}
