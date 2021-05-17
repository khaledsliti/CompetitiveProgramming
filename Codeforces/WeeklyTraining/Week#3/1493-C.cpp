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

const int N = 1e5 + 5;
const int A = 26;

int n, k;
string s;
int rem[A];

void update(int c, int v) {
  rem[c] = (rem[c] + v + k) % k;
}

int getNeed() {
  int need = 0;
  for(int i = 0; i < A; i++) {
    if(rem[i]) need += k - rem[i];
  }
  return need;
}

bool check(int idx, string& sol) {
  // cout << idx << " " << rem[0] << " " << rem[1] << " " << rem[2] << " " << sol << endl;
  for(int c = s[idx] - 'a' + 1; c < A; c++) {
    update(c, 1);
    int need = getNeed();
    int empty_pos = n - idx - 1;
    if(need <= empty_pos && (empty_pos - need) % k == 0) {
      string a = "";
      if(empty_pos > need) a = string(empty_pos - need, 'a');
      for(int i = 0; i < A; i++) {
        if(rem[i]) {
          int x = k - rem[i];
          while(x--) {
            a.push_back(char('a' + i));
          }
        }
      }
      sol += char('a' + c) + a;
      return true;
    }
    update(c, -1);
  }
  return false;
}

void solve() {
  cin >> n >> k >> s;
  if(n % k != 0) return void(cout << -1 << endl);
  for(int i = 0; i < A; i++) {
    rem[i] = 0;
  }
  for(int i = 0; i < n; i++) {
    update(s[i] - 'a', 1);
  }
  if(!getNeed()) {
    cout << s << endl;
    return;
  }
  string sol = s;
  for(int i = n - 1; i >= 0; i--) {
    sol.pop_back();
    update(s[i] - 'a', -1);
    if(check(i, sol)) {
      cout << sol << endl;
      return;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
