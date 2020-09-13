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

int adj[26][26];

string key[] = {
  "abcdefghi",
  "jklmnopqr",
  "stuvwxyz-"
};

void pre() {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 9; j++) {
      if(key[i][j] == '-') continue;
      int c1 = key[i][j] - 'a';
      for(int ii = 0; ii < 3; ii++) {
        for(int jj = 0; jj < 9; jj++) {
          int c2 = key[ii][jj] - 'a';
          if(key[ii][jj] == '-') continue;
          if(abs(i - ii) <= 1 && abs(j - jj) <= 1) {
            adj[c1][c2] = 1;
          }
        }
      }
    }
  }
}

bool similar(string a, string b) {
  if(sz(a) != sz(b)) return false;
  for(int i = 0; i < sz(a); i++) {
    if(!adj[a[i] - 'a'][b[i] - 'a'])
      return false;
  }
  return true;
}

int main()
{
  pre();
  int T;
  cin >> T;
  while(T--) {
    string a, b;
    cin >> a >> b;
    if(a == b) {
      cout << 1 << endl;
    } else if(similar(a, b)) {
      cout << 2 << endl;
    } else {
      cout << 3 << endl;
    }
  }
  return 0;
}
