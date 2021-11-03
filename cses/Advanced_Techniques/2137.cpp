#pragma GCC target("popcnt")

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

const int N = 3001;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n; cin >> n;
  bitset<N> arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int inter = (arr[i] & arr[j]).count();
      ans += inter * (inter - 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
