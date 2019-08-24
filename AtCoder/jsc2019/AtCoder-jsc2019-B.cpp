#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2005;
const int mod = 1e9 + 7;

int n;
long long k;
int arr[N];

int main()
{
  cin >> n >> k;
  long long v = k * (k - 1) / 2;
  v %= mod;
  long long ans = 0;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  for(int i = 0 ; i < n ; i++){
    int p = 0;
    for(int j = 0 ; j < i ; j++)
      p += arr[j] > arr[i];
    int r = 0;
    for(int j = 0 ; j < n ; j++)
      r += arr[j] > arr[i];
    long long cur = p * k + r * v;
    cur %= mod;
    ans = (ans + cur) % mod;
  }
  cout << ans << endl;
  return 0;
}
