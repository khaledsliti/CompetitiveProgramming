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

const int N = 1e7 + 1;

int n;
int isp[N], lg[N];
int tp[10];

int main()
{
  tp[0] = 1;
  for(int i = 1; i <= 7; i++)
    tp[i] = tp[i - 1] * 10;
  for(int i = 0; i < 10; i++)
    lg[i] = 0;
  for(int i = 10; i < N; i++)
    lg[i] = 1 + lg[i / 10];
  for(int i = 2; i < N; i++)
    isp[i] = 1;
  for(int i = 2; i * i < N; i++)
    if(isp[i])
      for(int j = i * i; j < N; j += i)
        isp[j] = 0;
  int tot = 0;
  for(int i = 2; i <= 1000000; i++) {
    int len = lg[i];
    int a = i;
    bool good = true;
    do {
      good &= isp[a];
      int l = a / tp[len];
      a = (a % tp[len]) * 10 + l;
    }while(a != i && good);
    tot += good;
  }
  cout << tot << endl;
  return 0;
}
