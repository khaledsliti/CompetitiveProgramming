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

int n;
ll P, Q, R;
int arr[N];
ll pref[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> P >> Q >> R;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    pref[i] = arr[i];
    if(i > 0) {
      pref[i] += pref[i - 1];
    }
  }

  auto sum = [&](int l, int r) -> ll {
    return pref[r] - (l > 0 ? pref[l - 1] : 0);
  };

  auto get = [&](int st, ll need) -> int {
    int low = st, high = n - 1;
    while(low <= high) {
      int mid = (low + high) >> 1;
      ll s = sum(st, mid);
      if(s < need) {
        low = mid + 1;
      } else if(s == need) {
        return mid;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  };

  for(int i = 0; i < n; i++) {
    int j = get(i, P);
    if(j == -1 || j + 1 >= n) continue;
    int k = get(j + 1, Q);
    if(k == -1 || k + 1 >= n) continue;
    int l = get(k + 1, R);
    if(l == -1) continue;
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}
