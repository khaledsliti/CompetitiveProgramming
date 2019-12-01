#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int D = 1e7 + 1;

int n, m;
char s[N], t[N];
int F[N];
int dp[D];

int solve(int i, int k);

int match(int i, int k)
{
  k++;
  if(k == m)
    return 1 + solve(i + 1, F[k - 1]);
  return solve(i + 1, k);
}

int solve(int i, int k)
{
  if(i >= n)
    return 0;
  int& r = dp[i * m + k];
  if(r != -1)
    return r;
  if(s[i] == t[k]){
    r = match(i, k);
  }else if(s[i] == '?'){
    r = 0;
    for(char c = 'a' ; c <= 'z' ; c++){
      if(c == t[k])
        r = max(r, match(i, k));
      else
        r = max(r, k == 0 ? solve(i + 1, 0) : solve(i, F[k - 1]));
    }
  }else{
    r = (k == 0 ? solve(i + 1, k) : solve(i, F[k - 1]));
  }
  return r;
}

int main()
{
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);
  F[0] = 0;
  for(int i = 1, k = 0 ; i < n ; i++){
    while(k > 0 && t[i] != t[k])
      k = F[k - 1];
    if(t[i] == t[k])
      k++;
    F[i] = k;
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
  return 0;
}
