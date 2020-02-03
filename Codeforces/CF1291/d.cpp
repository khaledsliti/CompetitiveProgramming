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

int n, q;
char s[N];
int cnt[N][A];

bool solve(int l, int r)
{
  if(l == r)
    return true;
  if(s[l] != s[r])
    return true;
  int tot = 0;
  for(int i = 0 ; i < A ; i++){
    if(cnt[r - 1][i] > cnt[l][i] && i != s[l] - 'a')
      tot++;
  }
  return tot > 1;
}

int main()
{
  scanf("%s", s);
  n = strlen(s);
  for(int i = 0 ; i < n ; i++){
    if(i > 0)
      for(int j = 0 ; j < A ; j++)
        cnt[i][j] = cnt[i - 1][j];
    cnt[i][s[i] - 'a']++;
  }
  scanf("%d", &q);
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%s\n", solve(--l, --r) ? "Yes" : "No");
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity