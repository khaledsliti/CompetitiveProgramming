// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int a[N], b[N];
set<int> pos[3];

void solve() {
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", a + i);
    pos[a[i] + 1].insert(i);
  }
  bool x = 0, y = 0;
  for(int i = 0 ; i < n ; i++)
    scanf("%d", b + i);
  for(int i = 0 ; i < n ; i++) {
    if(a[i] < b[i] && !x) {
      cout << "NO" << endl;
      return;
    }
    if(a[i] > b[i] && !y) {
      cout << "NO" << endl;
      return;
    }
    x |= a[i] == 1;
    y |= a[i] == -1;
  }
  cout << "YES" << endl;
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    solve();
  return 0;
}
