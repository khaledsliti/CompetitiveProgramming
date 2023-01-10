// RedStone
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

const int N = 2e5 + 5;

int n, m;
int arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long sum = 0, last = 0;
  for(int i = 0; i < m; i++) {
    sum += 1LL * (i + 1) * arr[i];
    last += arr[i];
  }
  long long ans = sum;
  for(int i = m; i < n; i++) {
    sum += 1LL * m * arr[i];
    sum -= last;
    last -= arr[i - m] - arr[i];
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
