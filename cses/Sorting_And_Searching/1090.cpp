// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;

int n, x;
int arr[N];

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  int last = n - 1;
  int ans = n;
  for(int i = 0; i < last; i++) {
    while(last > i && arr[i] + arr[last] > x)
      last--;
    if(i < last)
      ans--, last--;
  }
  cout << ans << endl;
  return 0;
}
