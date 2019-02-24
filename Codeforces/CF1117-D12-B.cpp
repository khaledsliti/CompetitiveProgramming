/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1117/problem/B

  Idea:
    Let the maximum element be a and the second maximum be b. So we need to take k elements with a value and one element with b value.
    Until we get m elements.

  Compexity:
    Time: O(NlogN)
    Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
typedef long long ll;

const int N = 2e5 + 4;

int n, m, k;
int arr[N];

int main()
{
  cin >> n >> m >> k;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  int a = arr[n - 1];
  int b = arr[n - 2];

  int t = m / (k + 1);

  long long ans = 1LL * t * (1LL * k * a + b);

  m %= (k + 1);

  if(m)
    ans += 1LL * m * a;

  cout << ans << endl;
  return 0;
}