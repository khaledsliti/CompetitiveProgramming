#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e7 + 5;

int n;
int smf[N];
int mu[N];

int getMu(int x)
{
  int sum = 0;
  for(int p = smf[x] ; x > 1 ; p = smf[x]){
    int cnt = 0;
    while(x % p == 0)
      x /= p, cnt++;
    if(cnt > 1)
      return 0;
    sum++;
  }
  if(sum & 1) return 1;
  return -1;
}

void pre()
{
  for(int i = 2 ; i < N ; i++)
    smf[i] = i;
  for(int i = 2 ; i < N ; i++){
    if(smf[i] == i){
      for(int j = i * 2 ; j < N ; j += i)
        smf[j] = min(smf[j], i);
    }
  }
  for(int i = 2 ; i < N ; i++)
    mu[i] = getMu(i);
}

int calc(int a, int b, int v)
{
  return b / v - (a - 1) / v;
}

int main()
{
  pre();
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans = 0;
  for(int i = 2 ; i < N ; i++){
    ans += mu[i] * 1LL * calc(a, b, i) * calc(c, d, i);
  }
  cout << (b - a + 1) * 1LL * (d - c + 1) - ans << endl;
  return 0;
}
