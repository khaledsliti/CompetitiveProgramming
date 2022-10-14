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
int arr[N];
map<int, vector<int>> pos;

vector<pair<int, int>> build(const vector<int>& pos) {
  vector<pair<int, int>> res;
  for(int i = 0; i < sz(pos); i++) {
    if(i > 0 && pos[i - 1] + 1 < pos[i]) {
      // D(pos[i - 1]); D(pos[i]);
      res.push_back({-(pos[i] - pos[i - 1] - 1), -1});
    }
    res.push_back({1, pos[i]});
  }
  // for(int i = 0; i < sz(pos); i++) {
  //   cout << pos[i] << ",  ";
  // }
  // cout << endl;
  // for(int i = 0; i < sz(res); i++) {
  //   cout << res[i].first << ", ";
  // }
  // cout << endl;
  return res;
}

// sum, l, r
array<int, 3> maxSum(const vector<pair<int, int>>& arr) {
  int max_so_far = -1e9;
  int cur_sum = 0;
  int left = 0, right = 0;
  int a = 0;
  for (int i=0; i< sz(arr); i++ ) {
    cur_sum += arr[i].first;
    if (max_so_far < cur_sum) {
      max_so_far = cur_sum;
      left = a;
      right = i;
    }
    if (cur_sum < 0) {
      cur_sum = 0;
      a = i + 1;
    }
  }
  return {max_so_far, arr[left].second, arr[right].second};
}

void solve() {
  cin >> n;
  pos.clear();
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    pos[arr[i]].push_back(i);
  }

  int best = -1, left, right, val;
  for(auto& x: pos) {
    vector<int>& v = x.second;
    auto r = maxSum(build(v));
    if(r[0] > best) {
      best = r[0];
      left = r[1], right = r[2];
      val = x.first;
    }
  }
  cout << val << " " << left + 1 << " " << right + 1 << endl;
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
