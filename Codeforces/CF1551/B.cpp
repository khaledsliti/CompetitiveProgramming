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

int n, k;
int arr[N], sol[N];

void solve() {
  cin >> n >> k;
  map<int, vector<int>> fr;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    fr[arr[i]].push_back(i);
    sol[i] = 0;
  }
  int ans = 0;
  vector<int> pos;
  for(auto x: fr) {
    if(x.second.size() >= k) {
      for(int i = 0; i < k; i++) {
        sol[x.second[i]] = i + 1;
      }
    } else {
      pos.insert(pos.end(), all(x.second));
    }
  }
  while(sz(pos) % k != 0) {
    pos.pop_back();
  }
  int cur = 0;
  for(int i = 0; i < sz(pos); i++) {
    sol[pos[i]] = cur + 1;
    cur = (cur + 1) % k;
  }
  for(int i = 0; i < n; i++) {
    cout << sol[i] << " ";
  }
  cout << endl;
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
