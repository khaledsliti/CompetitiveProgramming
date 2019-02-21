/*
  Author: RedStone

  Idea:
    The main idea is that if we have an array A of N elements such that A[0] ^ ... ^ A[N] = 0 and N is even
    Then we can say that A[0] ^ ... ^ A[N/2] = A[N/2+1] ^ ... ^ A[N]
    We can reach this equation if we XOR A[N/2+1] ^ ... ^ A[N] both sides
    So, the problem becames: Find the number of sub-arrays such that the XOR of all elements is zero.
    Since we are looking for sub-arrays with even length we must use two prefix arrays, one for even indexes and other for odd ones.

  Compexity: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
typedef long long ll;

const int N = 3e5 + 5;

int n;
int a[N];
int pref[N];
int cnt[1 << 21][2];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", a + i);
    pref[i + 1] = pref[i] ^ a[i];
  }
  long long ans = 0;
  cnt[0][0] = 1;
  int t = 1;
  for(int i = 1 ; i <= n ; i ++){
    ans += cnt[pref[i]][t];
    ++cnt[pref[i]][t];
    t ^= 1;
  }
  cout << ans << endl;
  return 0;
}