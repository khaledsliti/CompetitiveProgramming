#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n;
  scanf("%d", &n);
  if(n == 1) printf("-1\n");
  else printf("%d %d %d\n", n, n + 1, n * (n + 1));
  return 0;
}
