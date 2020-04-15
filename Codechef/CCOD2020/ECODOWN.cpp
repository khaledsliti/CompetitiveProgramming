// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int Mod = 1e9 + 6;
const int Len = 2;

void copy(long long a[Len][Len], long long b[Len][Len]) {
  for(int i = 0 ; i < Len ; i++)
    for(int j = 0 ; j < Len ; j++)
      a[i][j] = b[i][j];
}
void zero(long long a[Len][Len]) {
  for(int i = 0 ; i < Len ; i ++)
    for(int j = 0 ; j < Len ; j++)
      a[i][j] = 0;
}
void identity(long long a[Len][Len]) {
  zero(a);
  for(int i = 0 ; i < Len ; i++)
    a[i][i] = 1;
}
void multiply(long long r[Len][Len], long long a[Len][Len], long long b[Len][Len]) {
  for(int i = 0 ; i < Len ; i++)
    for(int j = 0 ; j < Len ; j++) {
      r[i][j] = 0;
      for(int k = 0 ; k < Len ; k++)
        r[i][j] += a[i][k] * b[k][j] % Mod, r[i][j] %= Mod;
    }
}

long long c[Len][Len], d[Len][Len];
void pow(long long b[Len][Len], long long a[Len][Len], int p) {
  if(!p) { identity(b); return; }
  pow(b, a, p >> 1);
  copy(c, b);
  copy(d, b);
  multiply(b, c, d);
  if(p & 1) {
    copy(c, b);
    multiply(b, a, c);
  }
}

pair<int, int> get_fib(int n) {
  if(n <= 0) return {0, 0};
  long long A[2][2] = {{1, 1}, {1, 0}};
  long long F[2][2];
  pow(F, A, n - 1);
  return {F[0][0], F[0][1]};
}

int po(int a, int b) {
  if(!b) return 1;
  int r = po(a, b >> 1);
  r = (1LL * r * r) % (Mod + 1);
  if(b & 1) r = (1LL * r * a) % (Mod + 1);
  return r;
}

int get(int p, int q, int n) {
  if(n == 0) return p;
  if(n == 1) return q;
  pair<int, int> fib = get_fib(n);
  assert(fib.first >= 0 && fib.first <= Mod);
  assert(fib.second >= 0 && fib.second <= Mod);
  int ans = 1LL * po(1 + q, fib.first) * po(1 + p, fib.second) % (Mod + 1);
  ans = (ans + Mod) % (Mod + 1);
  return ans;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, p, q;
    scanf("%d%d%d", &p, &q, &n);
    printf("%d\n", get(p, q, n));
  }
  return 0;
}
