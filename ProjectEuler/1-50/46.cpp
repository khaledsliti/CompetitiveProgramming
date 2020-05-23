// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e6 + 4;

int isp[N];

int main()
{
  for(int i = 2; i < N ; i++)
    isp[i] = 1;
  for(int i = 2; i * i < N; i++)
    if(isp[i])
      for(int j = i * i; j < N; j += i)
        isp[j] = 0;
  for(int n = 3; n < N; n += 2) {
    if(isp[n]) continue;
    bool good = false;
    for(int i = 1; i * i * 2 < n && !good; i++) {
      int p = n - 2 * i * i;
      if(isp[p]) {
        good = true;
      }
    }
    if(!good) {
      cout << n << endl;
      return 0;
    }
  }
  return 0;
}
