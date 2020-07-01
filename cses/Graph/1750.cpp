// We only fail when we stop trying
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
const int L = 31;

int n;
int nxt[N][L];


int main()
{
  int q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> nxt[i][0];
    --nxt[i][0];
  }
  for(int j = 1; j < L; j++) {
    for(int i = 0; i < n; i++) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    }
  }
  while(q--) {
    int src, dist;
    cin >> src >> dist;
    src--;
    for(int i = L - 1; i >= 0; i--)
      if(dist >= (1 << i)) {
        dist -= (1 << i);
        src = nxt[src][i];
      }
    cout << src + 1 << endl;
  }
  return 0;
}
