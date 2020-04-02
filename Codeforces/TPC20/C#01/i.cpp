// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef complex<int> point;

const int N = 1e5 + 5;

int n;
point pt[N], tpt[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    pt[i] = point(a, b);
    tpt[i] = point(a + b, b - a);
  }
  return 0;
}
