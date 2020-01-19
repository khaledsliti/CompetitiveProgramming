#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5e6 + 5;

int phi[N];
unsigned long long sum[N];

void pre()
{
  for(int i = 2 ; i < N ; i++)
    phi[i] = i;
  for(int i = 2 ; i < N ; i++){
    if(phi[i] == i)
      for(int j = i; j < N ; j += i)
        phi[j] -= phi[j] / i;
    sum[i] = 1LLU * phi[i] * phi[i] + sum[i - 1];
  }
}

int main()
{
  pre();
  int tests, tc = 1;
  scanf("%d", &tests);
  while(tests--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("Case %d: %llu\n", tc++, sum[b] - sum[a - 1]);
  }
  return 0;
}
