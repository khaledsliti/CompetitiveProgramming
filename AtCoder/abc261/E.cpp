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

const int L = 30;
const int N = 2e5 + 5;

int n, c;
int op[2][L][N];
int t[N], a[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> c;
  for(int i = 0; i < n; i++) {
    cin >> t[i] >> a[i];
  }
  for(int start = 0; start < 2; start++) {
    for(int b = 0; b < L; b++) {
      int cur = start;
      for(int i = 0; i < n; i++) {
        int rhs = (a[i] >> b) & 1;
        if(t[i] == 1) {
          cur &= rhs;
        } else if(t[i] == 2) {
          cur |= rhs;
        } else {
          cur ^= rhs;
        }
        op[start][b][i] = cur;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int b = 0; b < L; b++) {
      int start = (c >> b) & 1;
      int nw = op[start][b][i];
      if(start != nw) {
        c ^= 1 << b;
      }
    }
    cout << c << endl;
  }
  return 0;
}
/*
1010

op1: xor 11

*/