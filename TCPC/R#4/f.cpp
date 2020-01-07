#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5e6 + 5;

int n, k;
char s[N];
int fa[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%s%d", s, &k);
    n = strlen(s);
    fa[0] = 0;
    for(int i = 1, k = 0; i < n; i++){
      while(k && s[k] != s[i])
        k = fa[k - 1];
      if(s[i] == s[k]) k++;
      if(k == n) k = fa[k - 1];
      fa[i] = k;
    }
    printf("%I64d\n", 1LL * (n - fa[n - 1]) * k + fa[n - 1]);
  }
  return 0;
}
