// RedStone
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
const int L = 18;

int n, q;
int arr[N], smf[N];
int last[N];
int nxt[N][L];


void sieve() {
  for(int i = 0; i < N; i++) {
    smf[i] = i;
  }
  for(int i = 2; i * i < N; i++) {
    if(smf[i] == i) {
      for(int j = 2 * i; j < N; j += i) {
        smf[j] = min(smf[j], i);
      }
    }
  }
}

int main()
{
  sieve();

  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  for(int i = 0; i < N; i++) {
    last[i] = n;
  }
  nxt[n][0] = n;
  for(int i = n - 1; i >= 0; i--) {
    nxt[i][0] = n;
    for(int cur = arr[i]; cur > 1; ) {
      int p = smf[cur];
      nxt[i][0] = min(nxt[i][0], last[p]);
      last[p] = i;
      while(cur % p == 0) {
        cur /= p;
      }
    }
    nxt[i][0] = min(nxt[i][0], nxt[i + 1][0]);
  }
  for(int j = 1; j < L; j++) {
    for(int i = 0; i <= n; i++) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    }
  }

  while(q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    int steps = 0;
    for(int j = L - 1; j >= 0; j--) {
      if(nxt[l][j] < r) {
        l = nxt[l][j];
        steps |= (1 << j);
      }
    }
    printf("%d\n", steps + 1);
  }
  return 0;
}
