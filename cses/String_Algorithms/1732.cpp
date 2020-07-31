// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

void getZarr(char* str, int Z[])
{
  int n = strlen(str);
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
const int N = 1e6 + 5;

int n;
char s[N];
int z[N];


int main()
{
  scanf("%s", s);
  n = strlen(s);
  getZarr(s, z);
  for(int i = n - 1; i >= 0; i--) {
    if(i + z[i] >= n) {
      printf("%d ", n - i);
    }
  }
  printf("\n");
  return 0;
}
