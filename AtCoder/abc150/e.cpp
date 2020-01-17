#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n;
int arr[N];

int main()
{
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  sort(arr, arr + n, greater<int>());
  long long ans = 0;
  for(int i = 0 ; i < n ; i++){
    ans += (1LL * arr[i] * (i + 2)) % MOD;
    ans %= MOD;
  }
  for(int i = 1 ; i < n ; i++)
    ans = (ans * 4) % MOD;
  cout << ans << endl;
  return 0;
}
