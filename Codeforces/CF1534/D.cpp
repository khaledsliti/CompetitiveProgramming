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

const int N = 2007;

int n;
int maxLev;
int curLev[N];
vector<int> nodes[N];
int s[2];

void ask(int r) {
  cout << "? " << r + 1 << endl;
  cout.flush();
}

void readLev() {
  for(int i = 0; i < n; i++) {
    cin >> curLev[i];
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n;

  ask(0);
  readLev();
  
  vector<pair<int, int>> sol;
  for(int i = 0; i < n; i++) {
    maxLev = max(maxLev, curLev[i]);
    if(curLev[i] == 1) {
      sol.push_back({1, i + 1});
    }
    nodes[curLev[i]].push_back(i);
    s[curLev[i] & 1]++;
  }

  int start = s[0] <= s[1] ? 2 : 1;
  
  for(int lev = start; lev <= maxLev; lev += 2) {
    for(int u: nodes[lev]) {
      ask(u);
      readLev();
      for(int i = 1; i < n; i++) {
        if(curLev[i] == 1) {
          sol.push_back({u + 1, i + 1});
        }
      }
    }
  }

  assert(sz(sol) == n - 1);
  cout << "!" << endl;
  for(auto e: sol) {
    cout << e.first << " " << e.second << endl;
  }
  cout.flush();

  return 0;
}
