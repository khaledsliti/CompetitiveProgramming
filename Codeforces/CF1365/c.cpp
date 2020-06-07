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

int n;
int a[N], b[N], diff[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    a[--x] = i;
  }
  for(int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    b[--x] = i;
  }
  
  for(int i = 0; i < n; i++) {
    int d = b[i] - a[i];
    if(d < 0) d = n + d;
    diff[d]++;
  }
  int best = 0;
  for(int i = 0; i < n; i++)
    best = max(best, diff[i]);
  cout << best << endl;
  return 0;
}
