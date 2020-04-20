// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1000001;

int phi[N];
long long sum[N];

void calc_phi() {
  for(int i = 1 ; i < N ; i++)
    phi[i] = i;
  for(int i = 2 ; i < N ; i++)
    if(phi[i] == i) {
      for(int j = i ; j < N ; j += i)
        phi[j] -= phi[j] / i;
    }
}

int main()
{
  calc_phi();
  for(int i = N - 1 ; i >= 1 ; i--) {
    long long s = i > 2 ? 1LL * phi[i] * i / 2 : 1;
    for(int j = i ; j < N ; j += i)
      sum[j] += s;
  }
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", n * sum[n]);
  }
  return 0;
}
