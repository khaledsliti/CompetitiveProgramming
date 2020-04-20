// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2004;
const int Lim = 1e9;

int n;
string s;
int last[N];

void get(char c, int& dx, int& dy) {
  if(c == 'N') dx--;
  if(c == 'S') dx++;
  if(c == 'W') dy--;
  if(c == 'E') dy++;
}

void solve(int l, int r, int& dx, int& dy) {
  if(l > r) return;
  if(s[l] >= 'A' && s[l] <= 'Z') {
    get(s[l], dx, dy);
    dx = (dx % Lim + Lim) % Lim;
    dy = (dy % Lim + Lim) % Lim;
    solve(l + 1, r, dx, dy);
    return;
  } else if(s[l] >= '0' && s[l] <= '9') {
    int m = s[l] - '0';
    int x = 0, y = 0;
    solve(l + 2, last[l + 1] - 1, x, y);
    dx = ((dx + 1LL * m * x) % Lim + Lim) % Lim;
    dy = ((dy + 1LL * m * y) % Lim + Lim) % Lim;
    solve(last[l + 1] + 1, r, dx, dy);
  }
}

void solve() {
  cin >> s;
  n = sz(s);
  stack<int> st;
  for(int i = 0 ; i < n ; i++) {
    if(s[i] == '(') st.push(i);
    else if(s[i] == ')') last[st.top()] = i, st.pop();
  }
  int dx = 0, dy = 0;
  solve(0, n - 1, dx, dy);
  cout << dy + 1 << " " << dx + 1 << endl;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--) {
    cout << "Case #" << tc++ << ": ";
    solve();
  }
  return 0;
}
