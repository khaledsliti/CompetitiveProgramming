#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T;
  cin >> T;
  while(T--){
    int n, sum;
    cin >> n >> sum;
    int a = sum % n;
    int b = n - a;
    long long v = sum / n;
    long long res = a * (v + 1) * (v + 1) + b * v * v;
    cout << res << endl;
  }
  return 0;
}
