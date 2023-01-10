// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp ma// RedStone
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

int n, m;
int a[N];
vector<int> vals[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > n) {
      continue;
    }
    int v = a[i];
    if (a[i] < 0) {
      int k = (-a[i] + i) / (i + 1);
      v = a[i] + k * (i + 1);
    }
    while(v <= n) {
      int op = (v - a[i]) / (i + 1);
      if (op > m) {
        break;
      }
      vals[op].push_back(v);
      v += i + 1;
    }
  }
  for(int i = 1; i <= m; i++) {
    sort(all(vals[i]));
    vals[i].resize(unique(all(vals[i])) - begin(vals[i]));
    // cout << i << ": ";
    // for(int x : vals[i]) {
    //   cout << x << " ";
    // }
    // cout << endl;
    int mex = sz(vals[i]);
    for(int j = 0; j < sz(vals[i]); j++) {
      if(vals[i][j] != j) {
        mex = j;
        break;
      }
    }
    cout << mex << endl;
  }
  return 0;
}
ke_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;



int main()
{
  
  return 0;
}
