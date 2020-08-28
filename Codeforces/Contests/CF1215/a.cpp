#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()



int mn(int a1, int a2, int k1, int k2, int n)
{
  n-= (k1 - 1) * a1 + (k2 - 1) * a2;
  if(n <= 0)
    return 0;
  return min(a1 + a2, n);
}

int mx(int a1, int a2, int k1, int k2, int n)
{
  int f = min(a1, n / k1);
  n -= f * k1;
  int s = min(a2, n / k2);
  return f + s;
}

int main()
{
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  if(k1 > k2){
    swap(k1, k2);
    swap(a1, a2);
  }
  cout << mn(a1, a2, k1, k2, n) << " " << mx(a1, a2, k1, k2, n) << endl;
  return 0;
}
