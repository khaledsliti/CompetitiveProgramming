// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int ans[N];

int main()
{
  while(cin >> n) {
    int best = n + 1, b = n;
    for(int i = 2 ; i <= n ; i++) {
      int cur = (n + i - 1) / i + i;
      if(cur < best) {
        best = cur;
        b = i;
      }
    }
    int cur = 1;
    for(int i = n - 1 ; i >= 0 ; i -= b) {
      for(int j = max(0, i - b + 1) ; j <= i ; j++)
        ans[j] = cur++;
    }
    for(int i = 0 ; i < n ; i++)
      printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
