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

int n;

void solve(int n, int p) {
  if(n == 1) printf("%d\n", p);
  if(n == 2) printf("%d %d\n", p, p << 1);
  if(n == 3) printf("%d %d %d\n", p, p, p * 3);
  if(n >= 4) {
    for(int i = 0 ; i < ((n + 1) >> 1) ; i++)
      printf("%d ", p);
    solve(n >> 1, p << 1);
  }
}

int main()
{
  while(cin >> n) {
    solve(n, 1);
  }
  return 0;
}
