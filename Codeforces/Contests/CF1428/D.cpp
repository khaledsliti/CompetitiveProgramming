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

const int N = 1e5 + 5;

int n;
int a[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stack<pair<int, int>> one, two;
  vector<pair<int, int>> sol;
  int cur_row = n - 1;
  for(int j = n - 1; j >= 0; j--) {
    if(a[j] == 1) {
      if(cur_row < 0) {
        cout << -1 << endl;
        return 0;
      }
      one.push({cur_row, j});
      sol.push_back({cur_row, j});
      cur_row--;
    } else if(a[j] == 2) {
      if(one.empty()) {
        cout << -1 << endl;
        return 0;
      }
      auto pos_one = one.top();
      one.pop();
      two.push({pos_one.first, j});
      sol.push_back({pos_one.first, j});
    } else if(a[j] == 3) {
      pair<int, int> pos;
      if(two.empty() == false ){
        pos = two.top();
        two.pop();
      } else if(one.empty() == false) {
        pos = one.top();
        one.pop();
      } else {
        cout << -1 << endl;
        return 0;
      }
      if(cur_row < 0) {
        cout << -1 << endl;
        return 0;
      }
      sol.push_back({cur_row, j});
      sol.push_back({cur_row, pos.second});
      two.push({cur_row, j});
      cur_row--;
    }
  }

  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    cout << sol[i].first + 1 << " " << sol[i].second + 1 << endl;
  }
  return 0;
}
