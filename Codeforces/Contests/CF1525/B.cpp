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

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  bool sorted = true;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    sorted &= arr[i] == i + 1;
  }
  if(sorted) cout << 0 << endl;
  else if(arr[0] == 1 || arr[n - 1] == n) cout << 1 << endl;
  else if(arr[0] != n || arr[n - 1] != 1) cout << 2 << endl;
  else cout << 3 << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
