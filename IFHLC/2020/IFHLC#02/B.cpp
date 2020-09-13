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

const int K = 30'000'001;
const int N =    200'007;
const int L = 25;

int n, k;
bool isp[K];
int pr[K];
int num[L];
long long Cnk[L][L];


int calc(int x, int b) {
  for(int i = 0; i < L; i++) {
    num[i] = (x >> i) & 1;
  }
  int res = __builtin_popcount(x) == b;
  int prv = 0;
  for(int i = L - 1; i >= 0; i--) {
    if(num[i] == 1) {
      int need = b - prv;
      if(need < 0) {
        break;
      }
      if(i >= need) {
        res += Cnk[i][need];
      }
      prv++;
    }
  }
  return res;
}

void add(int& cur, int y) { // add y heads
  cur = min(cur + y, K - 1);
}

void erase(int& cur, int b) { // erase all numbers with b bits
  int tot = calc(cur, b);
  cur -= tot;
}

int main()
{  
  #ifndef LOCAL
  freopen("monster.in", "r", stdin);
  freopen("monster.out", "w", stdout);
  #endif

  for(int i = 2; i < K; i++) {
    isp[i] = 1;
  }
  for(int i = 2; i * i < K; i++) {
    if(isp[i]) {
      for(int j = i * i; j < K; j += i) {
        isp[j] = 0;
      }
    }
  }
  for(int i = 3; i < K; i++) {
    if(isp[i - 1] == 1) {
      pr[i] = i - 1;
    } else {
      pr[i] = pr[i - 1];
    }
  }

  Cnk[0][0] = 1;
  for(int i = 1; i < L; i++) {
    for(int j = 0; j <= i; j++) {
      if(i == j || j == 0) Cnk[i][j] = 1;
      else Cnk[i][j] = Cnk[i - 1][j] + Cnk[i - 1][j - 1];
    }
  }

  scanf("%d%d", &k, &n);
  int cur = 0;
  add(cur, k);
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if(x & 1) {
      int y = pr[x];
      add(cur, y - 1);
    } else {
      erase(cur, __builtin_popcount(x));
    }
  }

  printf("%d\n", cur);
  return 0;
}
