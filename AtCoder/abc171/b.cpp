// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1001;

int n, k;
int arr[N];

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  int ans = 0;
  for(int i = 0; i < k; i++)
    ans += arr[i];
  cout << ans << endl;
  return 0;
}
