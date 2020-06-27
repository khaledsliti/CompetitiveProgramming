// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1003;

int n, q;
int cur[N][N];
int bit[N][N];

void add(int a, int b, int val) {
  for(int i = a; i < N; i += i & -i)
    for(int j = b; j < N; j += j & -j)
      bit[i][j] += val;
}

int get(int a, int b) {
  int r = 0;
  for(int i = a; i > 0; i -= i & -i)
    for(int j = b; j > 0; j -= j & -j)
      r += bit[i][j];
  return r;
}

int main()
{
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if(c == '*') {
        add(i + 1, j + 1, 1);
        cur[i][j] = 1;
      }
    }
  }
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int x, y;
      cin >> x >> y;
      add(x, y, cur[x - 1][y - 1] ? -1 : 1);
      cur[x - 1][y - 1] ^= 1;
    } else {
      int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1) << endl;
    } 
  }
  return 0;
}
