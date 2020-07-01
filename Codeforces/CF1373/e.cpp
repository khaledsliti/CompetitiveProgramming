// We only fail when we stop trying
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

void solve() {
  cin >> n >> k;
  k++;
  vector<string> sol;
  int Len = 200;
  for(int len = 1; len < Len; len++) {
    for(int d = 0; d <= 9; d++) {
      int add = 0;
      int sum = 0;
      for(int i = 0; i < k; i++) {
        add += (d + i) / 10;
        sum += (d + i) % 10;
      }
      for(int x = 1; x < len - 1; x++) {
        for(int a = 0; a < 9; a++) {
          int cur = sum + 9 * (x - 1) * (k - add) + a * (k - add) + (a + 1) * add;
          if(cur < n) {
            int cnt = len - x - 1;
            int rem = n - cur;
            if(rem > 0 && rem % k == 0) {
              int s = rem / k;
              if(s >= cnt) {
                s -= cnt;
                string cur_sol(cnt, '1');
                for(int i = 0; i < sz(cur_sol); i++)
                  while(s > 0 && cur_sol[i] < '9')
                    s--, cur_sol[i]++;
                sol.push_back(char(d + '0') + string(x - 1, '9') + char('0' + a) + cur_sol);
              }
            }
          }
        }
      }
    }
  }
  if(!sol.size()) return void(cout << -1 << endl);
  sort(all(sol));
  cout << sol.front() << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
