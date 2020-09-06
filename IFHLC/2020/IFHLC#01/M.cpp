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

const int N = 32, M = 8;
const int STONE = 0, SAND = 3, WATER = 2, SUGAR = 1;

int n, m;
int mat[N][M];
int dp[N][6568];
int sol[N][M];

char get_char(int x) {
  if(x == WATER) return 'O';
  if(x == SUGAR) return 'X';
  if(x == SAND) return '.';
  if(x == STONE) return '#';
  return -1;
};

void print() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << get_char(sol[i][j]);
    }
    cout << endl;
  }
}

int getMask(vector<int>& msk) {
  int r = 0;
  for(int i = m - 1; i >= 0; i--) {
    r = r * 3 + msk[i];
  }
  return r;
}

vector<int> getArray(int mask) {
  vector<int> msk(m);
  for(int i = 0; i < m; i++) {
    msk[i] = mask % 3;
    mask /= 3;
  }
  return msk;
}

int solve(int i, int mask) {
  int& res = dp[i][mask];
  if(res != -1) {
    return res;
  }
  auto msk = getArray(mask);
  if(i >= n) {
    for(int j = 0; j < m; j++) {
      if(msk[j] == SUGAR)
        return res = -1e9;
    }
    return res = 0;
  }
  res = -1e9;
  for(int cur = 0; cur < (1 << m); cur++) {
    int cost = 0;
    vector<int> col(m);
    for(int j = 0; j < m; j++) {
      if(mat[i][j] == STONE) {
        col[j] = STONE;
      } else if(cur & (1 << j)) {
        col[j] = WATER;
      } else {
        col[j] = SUGAR;
        cost++;
      }
    }
    vector<int> tmp(m);
    for(int j = 0; j < m; j++) {
      if(col[j] == SUGAR) {
        if(msk[j] == WATER || j > 0 && col[j - 1] == WATER || j + 1 < m && col[j + 1] == WATER) {
          tmp[j] = STONE;
        } else {
          tmp[j] = SUGAR;
        }
      } else {
        tmp[j] = col[j];
      }
    }
    bool valid = true;
    for(int j = 0; j < m; j++) {
      if(msk[j] == SUGAR && col[j] != WATER)
        valid = false;
    }
    if(valid) {
      res = max(res, cost + solve(i + 1, getMask(tmp)));
    }
  }
  return res;
}

void trace(int i, int mask) {
  if(i >= n) {
    return;
  }
  auto msk = getArray(mask);
  for(int cur = 0; cur < (1 << m); cur++) {
    int cost = 0;
    vector<int> col(m);
    for(int j = 0; j < m; j++) {
      if(mat[i][j] == STONE) {
        col[j] = STONE;
      } else if(cur & (1 << j)) {
        col[j] = WATER;
      } else {
        col[j] = SUGAR;
        cost++;
      }
    }
    vector<int> tmp(m);
    for(int j = 0; j < m; j++) {
      if(col[j] == SUGAR) {
        if(msk[j] == WATER || j > 0 && col[j - 1] == WATER || j + 1 < m && col[j + 1] == WATER) {
          tmp[j] = STONE;
        } else {
          tmp[j] = SUGAR;
        }
      } else {
        tmp[j] = col[j];
      }
    }
    bool valid = true;
    for(int j = 0; j < m; j++) {
      if(msk[j] == SUGAR && col[j] != WATER)
        valid = false;
    }
    if(valid && solve(i + 1, getMask(tmp)) + cost == solve(i, mask)) {
      for(int j = 0; j < m; j++) {
        sol[i][j] = col[j];
      }
      trace(i + 1, getMask(tmp));
      return;
    }
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c; cin >> c;
      if(c == '.') mat[i][j] = SAND;
      else mat[i][j] = STONE;
    }
  }
  memset(dp, -1, sizeof dp);
  vector<int> msk(m, STONE);
  solve(0, getMask(msk));
  trace(0, getMask(msk));
  print();
  return 0;
}
