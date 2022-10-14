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

const int N = 2e5 + 5;
const int L = 30;

struct Q{
  int i, j, x;
};

int n, q;
Q qr[N];
int fx[N];
int ans_b[N];
int ans[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for(int i = 0; i < q; i++) {
    cin >> qr[i].i >> qr[i].j >> qr[i].x;
    qr[i].i--, qr[i].j--;
  }

  for(int b = 0; b < L; b++) {
    for(int i = 0; i < n; i++) {
      fx[i] = 0;
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < q; i++) {
      if(qr[i].i == qr[i].j) {
        fx[qr[i].i] = 1;
        ans_b[qr[i].i] = (qr[i].x >> b) & 1;
        continue;
      }
      if(qr[i].x & (1 << b)) {
        g[qr[i].i].push_back(qr[i].j);
        g[qr[i].j].push_back(qr[i].i);
      } else {
        fx[qr[i].i] = fx[qr[i].j] = 1;
        ans_b[qr[i].i] = ans_b[qr[i].j] = 0;
      }
    }
    for(int i = 0; i < n; i++) {
      if(fx[i] == 1) {
        continue;
      }
      bool should = false;
      for(int j : g[i]) {
        if(fx[j] && ans_b[j] == 0) {
          should = true;
          break;
        }
      }
      fx[i] = 1;
      ans_b[i] = should ? 1 : 0;
    }
    for(int i = 0; i < n; i++) {
      if(ans_b[i]) {
        ans[i] |= (1 << b);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
