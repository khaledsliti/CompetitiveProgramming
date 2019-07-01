/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://www.facebook.com/hackercup/problem/2448144345414246/

  Idea:
    we go from right to left and for each B we can decide greedly if we have to change it to A or not.
    For each i, we have already fixed all j > i, so we have to change it if and only if it brokes the rule (b - a > k) (we track the maximum position with max (b - a) so far)

  Compexity:
    Time: O(N ^ 3)
    Memory: O(N ^ 2)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int oo = 1e9;
const int mod = 1e9 + 7;

int n, k;
char s[N];
int po[N];

int main()
{
  po[0] = 2;
  for(int i = 1 ; i < N ; i++)
    po[i] = (po[i - 1] * 2) % mod;

  int T, tc(1);
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    int ans = 0;
    int mxDiff = -oo;
    for(int i = n - 1 ; i >= 0 ; i--) {
      if(s[i] == 'A') {
        mxDiff = max(mxDiff - 1, -1);
      }else{
        if(k == 0){
          ans = (ans + po[i]) % mod;
        }else{
          if(mxDiff + 1 > k) { // switch to A
            ans = (ans + po[i]) % mod;
            mxDiff = max(mxDiff - 1, -1);
          }else{
            mxDiff = max(mxDiff + 1, 1);
          }
        }
      }
    }
    cout << "Case #" << tc++ << ": " << ans << endl;
  }
  return 0;
}
