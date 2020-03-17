// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1505;
const int A = 26;

int n;
char s[N];
int ans[A][N];

int main()
{
  scanf("%d%s", &n, s);
  for(int a = 0 ; a < A ; a++) {
    for(int i = 0 ; i < n ; i++) {
      int acc = 0;
      for(int j = i ; j < n ; j++) {
        acc += (s[j] - 'a') != a;
        ans[a][acc] = max(ans[a][acc], j - i + 1);
      }
    }
    for(int i = 1 ; i <= n ; i++) {
      ans[a][i] = max(ans[a][i], ans[a][i - 1]);
    }
  }
  int q;
  scanf("%d", &q);
  while(q--) {
    int m;
    char c;
    scanf("%d %c", &m, &c);
    printf("%d\n", ans[c - 'a'][m]);
  }
  return 0;
}