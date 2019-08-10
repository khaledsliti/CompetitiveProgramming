#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n;
char tmp[10005];
vector<string> s;

bool check(string& s, string& p)
{
  if(sz(s) > sz(p))
    return false;
  for(int i = 0 ; i < sz(s) ; i++){
    if(s[i] != p[i])
      return false;
  }
  return true;
}

int main()
{
  int T, tc(1);
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    s.clear();
    for(int i = 0 ; i < n ; i++){
      scanf("%s", tmp);
      s.pb((string)tmp);
    }
    sort(all(s));
    bool yes = true;
    for(int i = 1 ; i < n && yes ; i++){
      if(check(s[i - 1], s[i]))
        yes = false;
    }
    printf("Case %d: %s\n", tc++, yes ? "YES" : "NO");
  }
  return 0;
}
