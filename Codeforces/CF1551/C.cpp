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
const int A = 26;

int n;
vector<string> arr;

int calc(const string& s, int d) {
  int res = 0;
  for(char c: s) {
    if(c - 'a' == d) res++;
    else res--;
  }
  return res;
}

int solve(int d) {
  vector<int> diff;
  for(int i = 0; i < n; i++) {
    diff.push_back(calc(arr[i], d));
  }
  sort(all(diff));
  reverse(all(diff));
  int ans = 0;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    if(sum + diff[i] > 0) {
      sum += diff[i];
      ans++;
    } else {
      break;
    }
  }
  return ans;
}

void solve() {
  cin >> n;
  arr.clear(); arr.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int ans = 0;
  for(int d = 0; d < A; d++) {
    ans = max(ans, solve(d));
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
