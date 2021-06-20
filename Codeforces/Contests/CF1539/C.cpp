// Guess Who's Back
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

int n;
long long x, k;
long long arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k >> x;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  vector<long long> diff;
  for(int i = 0; i < n - 1; i++) {
    if(arr[i + 1] - arr[i] > x) {
      diff.push_back(arr[i + 1] - arr[i]);
    }
  }
  sort(all(diff));
  for(int i = 0; i < sz(diff); i++) {
    long long need = (diff[i] - 1) / x;
    if(k >= need) {
      k -= need;
    } else {
      cout << 1 + sz(diff) - i << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0;
}
