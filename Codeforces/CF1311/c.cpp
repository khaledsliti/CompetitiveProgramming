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
const int A = 26;

int n, m;
char s[N];
int cnt[N][A];
long long tot[A];

void pre()
{
  for(int i = 0 ; i < A ; i++)  
    cnt[0][i] = (s[0] == char('a' + i));
  for(int i = 1 ; i < n ; i++){
    for(int j = 0 ; j < A ; j++)
      cnt[i][j] = cnt[i - 1][j] + (s[i] == char('a' + j));
  }
}

void add(int len)
{
  for(int i = 0 ; i < A ; i++)
    tot[i] += cnt[len - 1][i];
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    pre();
    for(int i = 0 ; i < m ; i++){
      int len;
      scanf("%d", &len);
      add(len);
    }
    add(n);
    for(int i = 0 ; i < A ; i++){
      printf("%I64d ", tot[i]);
      tot[i] = 0;
    }
    printf("\n");
  }
  return 0;
}
