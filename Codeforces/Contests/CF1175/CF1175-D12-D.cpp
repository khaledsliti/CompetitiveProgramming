#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n, k;
long long arr[N];

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++)
    scanf("%I64d", arr + i);
  for(int i = n - 2 ; i >= 0 ; i--)
    arr[i] += arr[i + 1];
  arr[n] = -1e18;
  long long ans = arr[0];
  sort(arr + 1, arr + n);
  for(int i = n - 1, rem = k - 1 ; i >= 0 && rem > 0 ; i--, rem--){
    ans += arr[i];
  }
  cout << ans << endl;
  return 0;
}
