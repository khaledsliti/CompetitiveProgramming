// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 7;

int isp[N];
int tp[10], lg[N];
int lf[N], rt[N];

int main()
{
  for(int i = 2; i < N; i++)
    isp[i] = 1;
  for(int i = 2; i * i < N; i++)
    if(isp[i])
      for(int j = i * i; j < N; j += i)
        isp[j] = 0;
  for(int i = 10; i < N; i++)
    lg[i] = 1 + lg[i / 10];
  tp[0] = 1;
  for(int i = 1; i < 10; i++)
    tp[i] = 10 * tp[i - 1];
  for(int i = 0; i < 10; i++) {
    lf[i] = rt[i] = isp[i];
  }
  int sum = 0;
  int n;
  cin >> n;
  for(int i = 10; i < n; i++) {
    if(isp[i]) {
      rt[i] = rt[i / 10];
      lf[i] = lf[i % tp[lg[i]]];
      if(rt[i] && lf[i]) {
        sum += i;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
