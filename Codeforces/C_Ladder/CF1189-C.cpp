#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int L = 18;

int n, q;
int s[N][L];
int v[N][L];
int lo[N];

int main()
{
  lo[1] = 0;
  for(int i = 2 ; i < N ; i++)
    lo[i] = 1 + lo[i >> 1];
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", &s[i][0]);
  for(int j = 1 ; (1 << j) <= n ; j++) {
    for(int i = 0 ; i + (1 << j) <= n ; i++){
      s[i][j] = s[i][j - 1] + s[i + (1 << (j - 1))][j - 1];
      v[i][j] = v[i][j - 1] + v[i + (1 << (j - 1))][j - 1] + (s[i][j] > 9);
      s[i][j] %= 10;
    }
  }
  scanf("%d", &q);
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    int len = r - l + 1;
    printf("%d\n", v[l - 1][lo[len]]);
  }
  return 0;
}
