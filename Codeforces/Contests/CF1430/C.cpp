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

int n;

void solve() {
  scanf("%d", &n);
  int act = n;
  printf("2\n");
  for(int i = n - 1; i >= 1; i--) {
    printf("%d %d\n", i, act);
    act = (act + i + 1) / 2;
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
