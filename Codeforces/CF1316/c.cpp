// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 5;

int n, m, p;
int a[N], b[N];

int main()
{
  scanf("%d%d%d", &n, &m, &p);
  int x = -1, y = -1;
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", a + i);
    if(a[i] % p != 0 && x == -1)
      x = i;
  }
  for(int i = 0 ; i < m ; i++) {
    scanf("%d", b + i);
    if(b[i] % p != 0 && y == -1)
      y = i;
  }
  cout << x + y << endl;
  return 0;
}
