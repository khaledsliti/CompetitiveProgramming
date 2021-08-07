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

const int L = 20;
const int N = (1 << L) + 1;

int n, k;
int bit[N];

void add(int idx, int val) {
  for(int i = idx + 1; i < N; i += i & -i) {
    bit[i] += val;
  }
}

void solve(int test) {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++)
    add(i, 1);
  for(int i = 0; i < n; i++) {
    int rem = n - i;
    
  }
}

int main()
{
  int tests;
  scanf("%d", &tests);
  for(int t = 1; t <= tests; t++) {
    solve(t);
  }
  return 0;
}
