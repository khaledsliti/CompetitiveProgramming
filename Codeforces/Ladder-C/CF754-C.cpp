// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 101;

int n, m;
string user[N];
unordered_map<string, int> id;
string chat[N];
int index[N];
vector<int> nxt[N];
int dp[N][N];

vector<int> getUsers(string str) {
  for(int i = 0 ; i < sz(str); i++) {
    bool space = false;
    for(char c : {'.', ',', '!', '?'})
      if(c == str[i])
        space = true;
    if(space) str[i] = ' ';
  }
  str += ' ';
  string cur = "";
  vector<int> res;
  for(int i = 0 ; i < sz(str) ; i++) {
    if(str[i] == ' ') {
      if(id.count(cur))
        res.push_back(id[cur]);
      cur = "";
    } else cur += str[i];
  }
  return res;
}

void clean(int idx) {
  string u = "";
  int b = 0;
  while(chat[idx][b] != ':')
    u += chat[idx][b++];
  b++;
  nxt[idx] = getUsers(chat[idx].substr(b));
  if(u != "?") index[idx] = id[u];
  else index[idx] = -1;
}

int solve(int idx, int last) {
  if(idx >= m) return 1;
  int& r = dp[idx][last + 1];
  if(r != -1) return r;
  set<int> ok;
  for(int i = 0 ; i < n ; i++)
    ok.insert(i);
  for(int x : nxt[idx])
    ok.erase(x);
  ok.erase(last);
  r = 0;
  if(index[idx] == -1) {
    for(int x : ok)
      r |= solve(idx + 1, x);
  } else {
    if(!ok.count(index[idx]))
      r = 0;
    else
      r = solve(idx + 1, index[idx]);
  }
  return r;
}

void trace(int idx, int last) {
  if(idx >= m) return;
  set<int> ok;
  for(int i = 0 ; i < n ; i++)
    ok.insert(i);
  for(int x : nxt[idx])
    ok.erase(x);
  ok.erase(last);
  if(index[idx] != -1) {
    trace(idx + 1, index[idx]);
  } else {
    set<int> ok;
    for(int i = 0 ; i < n ; i++)
      ok.insert(i);
    for(int x : nxt[idx])
      ok.erase(x);
    ok.erase(last);
    for(int x : ok)
      if(solve(idx + 1, x)) {
        index[idx] = x;
        trace(idx + 1, x);
        break;
      }
  }
}

void solve() {
  cin >> n;
  id.clear();
  for(int i = 0 ; i < n ; i++)
    cin >> user[i], id[user[i]] = i;
  cin >> m;
  cin.ignore();
  for(int i = 0 ; i < m ; i++) {
    getline(cin, chat[i]);
    clean(i);
  }
  for(int i = 0 ; i < m ; i++)
    for(int j = 0 ; j <= n ; j++)
      dp[i][j] = -1;
  if(!solve(0, -1)) {
    cout << "Impossible" << endl;
  } else {
    trace(0, -1);
    for(int i = 0 ; i < m ; i++) {
      if(chat[i][0] == '?') {
        cout << user[index[i]] << chat[i].substr(1) << endl;
      } else {
        cout << chat[i] << endl;
      }
    }
  }
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
