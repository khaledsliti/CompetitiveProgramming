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

const int N = 1e5 + 5;

int n;
array<int, 2> arr[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
  sort(arr, arr + n, [](const array<int, 2>& a, const array<int, 2>& b) {
    return a[0] - a[1] > b[0] - b[1];
  });
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans += 1LL * i * arr[i][0] + 1LL * (n - 1 - i) * arr[i][1];
  }
  cout << ans << endl;
  return 0;
}
