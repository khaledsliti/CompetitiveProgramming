// Guess Who's Back
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

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    int n; scanf("%d", &n);
    printf("%d\n", ((n + 1) * (n + 1) >> 1) - 1);
  }
  return 0;
}
