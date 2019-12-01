#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int arr[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  for(int i = 1 ; i < n ; i++)
    arr[i] -= arr[0];
  arr[0] = 0;
  int g = 0;
  for(int i = 1 ; i < n ; i++)
    g = __gcd(g, arr[i] - arr[i - 1]);
  int ans = 0;
  // for(int i = 0 ; i < n ; i++)
  //   cout << arr[i] << " ";
  // cout << endl;
  for(int i = 1 ; i < n ; i++){
    ans += (arr[i] - arr[i - 1] - 1) / g;
  }
  cout << ans << endl;
  return 0;
}
