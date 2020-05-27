#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5;

int n;
char s[N], r[N];
int zs[N], zr[N];

void getZarr(char* str, int n, int Z[])
{
  int L = 0, R = 0;
  for(int i = 1 ; i < n ; i++){
    if(i>R){
      L = R = i;
      while(R < n && str[R] == str[R-L]) ++R;
      Z[i] = R - L;
      --R;
    }else{
      int k = i - L;
      if(Z[k] <= R - i) Z[i] = Z[k];
      else{
        L = i;
        while(R<n && str[R-L] == str[R]) ++R;
        Z[i] = R-L;
        --R;
      }
    }
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%s", s);
    n = strlen(s);
    memcpy(r, s, strlen(s));
    reverse(r, r + strlen(s));
    getZarr(s, n, zs);
    getZarr(r, n, zr);
    int ans = 0;
    for(int i = 0; i < n - 2; i++) {
      int len1 = i + 1;
      int len2 = n - len1;
      if((len1 & 1) || (len2 & 1))
        continue;
      if(zs[len1 / 2] >= len1 /  2 && zr[len2 / 2] >= len2 / 2)
        ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
