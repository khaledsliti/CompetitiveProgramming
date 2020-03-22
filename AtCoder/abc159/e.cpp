// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 10;
const int M = 1100;

int n, m, k;
string s[N];
int mx[M];
vector<vector<int>> row;

int get(int mask, int i) {
  return (mask >> i) & 1;
}

void build(int mask) {
  row.clear();
  for(int i = 0 ; i < n ; i++) {
    vector<int> val(m, 0);
    int j = i;
    while(j < n && get(mask, i) == get(mask, j)){
      for(int c = 0 ; c < m ; c++) {
        val[c] += s[j][c] == '1';
      }
      j++;
    }
    row.push_back(val);
    i = j - 1;
  }
}

int solve() {
  int ans = sz(row) - 1;
  vector<int> cur(n, 0);
  for(int j = 0 ; j < m ; j++) {
    bool can = true;
    for(int i = 0 ; i < sz(row) ; i++) {
      if(row[i][j] > k) return n * m;
      can &= (cur[i] + row[i][j]) <= k;
    }
    if(can) {
      for(int i = 0 ; i < sz(row) ; i++) {
        cur[i] += row[i][j];
      }
    } else {
      ans++;
      for(int i = 0 ; i < sz(row) ; i++) {
        cur[i] = row[i][j];
      }
    }
  }
  return ans;
}

void print() {
  cout << sz(row) << endl;
  for(int i = 0 ; i < sz(row) ; i++) {
    for(int j = 0 ; j < m ; j++)
      cout << row[i][j] << " ";
    cout << endl;
  }
}

int main()
{
  cin >> n >> m >> k;
  for(int i = 0 ; i < n ; i++)
    cin >> s[i];
  int best = n * m;
  for(int mask = 0 ; mask < (1 << n) ; mask++) {
    build(mask);
    // print();
    best = min(best, solve());
  }
  cout << best << endl;
  return 0;
}
