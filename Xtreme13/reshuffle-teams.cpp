#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
char s[N];
string order = "ABCD";
int pref[4][N];
int cnt[4];

void build(int* arr, char c)
{
  for(int i = 0 ; i < n ; i++){
    if(s[i] != c)
      arr[i] = 1;
    else
      arr[i] = 0;
    if(i)
      arr[i] += arr[i - 1];
  }
}

int get(int* arr, int s, int e)
{
  return arr[e] + (s > e ? arr[n - 1] : 0) - (s > 0 ? arr[s - 1] : 0);
}

int solve(int st)
{
  int res = 0;
  for(int i = 0 ; i < sz(order) ; i++){
    int cur = order[i] - 'A';
    if(cnt[cur] == 0)
      continue;
    int nxt = (st + cnt[cur] - 1) % n;
    // cout << cur << " " << st << " " << nxt << endl;
    res += get(pref[cur], st, nxt);
    st = nxt + 1;
  }
  return res;
}

int solve()
{
  n = strlen(s);
  memset(cnt, 0, sizeof cnt);
  for(int i = 0 ; i < n ; i++)
    cnt[s[i] - 'A']++;
  for(int i = 0 ; i < 4 ; i++)
    build(pref[i], 'A' + i);
  int best = 1e9;
  do{
    for(int st = 0 ; st < n ; st++)
      best = min(best, solve(st));
  }while(next_permutation(all(order)));
  return best;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%s", s);
    printf("%d\n", solve());
  }
  return 0;
}
