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

const int N = 1000001;

int n;
char s[N];

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%s", &n, s);
    int a = 0, b = 0;
    for(int i = 0; i < n; i++)
      if(s[i] == 'A') a++;
      else b++;
    if(abs(a - b) == 1) printf("Case #%d: Y\n", tc++);
    else printf("Case #%d: N\n", tc++);
  }
  return 0;
}
