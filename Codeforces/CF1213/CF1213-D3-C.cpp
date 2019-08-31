#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long n, m;
int r[11];

int main()
{
  int q;
  cin >> q;
  while(q--){
    cin >> n >> m;
    long long sum = 0;
    for(int i = 1 ; i < 10 ; i++)
      r[i] = (1LL * i * m) % 10, sum += r[i];
    long long d = n / m;
    sum *= d / 10;
    for(int i = 1 ; i <= d % 10 ; i++)
      sum += r[i];
    cout << sum << endl;
  }
  return 0;
}
