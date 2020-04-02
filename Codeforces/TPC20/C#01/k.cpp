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
const int V = 2000;

int n, x;
bitset<V> bs;

int main()
{
  scanf("%d%d", &n, &x);
  for(int i = 0 ; i < n ; i++) {
    int a;
    scanf("%d", &a);
    a %= x;
    bs |= (bs << a);
    bs |= (bs >> x);
    bs[a] = 1;
  }
  cout << (bs[0] ? "YES" : "NO") << endl;
  return 0;
}
