// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 10055;

string s[3];
int can[3][3][N];

void calc(int i, int j) {
  string& a = s[i];
  string& b = s[j];
  for(int k = 0 ; k < sz(a) ; k++) {
    can[i][j][k] = true;
    for(int l = k ; l < sz(a) && l - k < sz(b) ; l++) {
      can[i][j][k] &= a[l] == '?' || b[l - k] == '?' || a[l] == b[l - k];
    }
  }
  for(int k = sz(a) ; k < N ; k++)
    can[i][j][k] = true;
}

int solve(vector<int>& idx) {
  int a = sz(s[idx[0]]);
  int b = sz(s[idx[1]]);
  int c = sz(s[idx[2]]);
  int ans = 1e9;
  for(int i = 0 ; i <= a ; i++) {
    if(can[idx[0]][idx[1]][i]) {
      for(int j = 0 ; j <= b || i + j <= a ; j++) {
        if(can[idx[1]][idx[2]][j] && can[idx[0]][idx[2]][i + j]) {
          ans = min(ans, max(a, max(b + i, c + i + j)));
        }
      }
    }
  }
  return ans;
}

int main()
{
  for(int i = 0 ; i < 3 ; i++)
    cin >> s[i];
  for(int i = 0 ; i < 3 ; i++)
    for(int j = 0 ; j < 3 ; j++)
      if(i != j)
        calc(i, j);
  vector<int> idx = {0, 1, 2};
  int best = 1e9;
  do {
    best = min(best, solve(idx));
  }while(next_permutation(all(idx)));
  cout << best << endl;
  return 0;
}
