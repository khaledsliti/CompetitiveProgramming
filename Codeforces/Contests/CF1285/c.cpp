#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main()
{
  long long x;
  cin >> x;
  vector<long long> pr;
  for(long long i = 2 ; i * i <= x ; i++){
    long long p = 1;
    while(x % i == 0){
      p *= i;
      x /= i;
    }
    if(p > 1)
      pr.pb(p);
  }
  if(x > 1) pr.pb(x);
  // for(auto v : pr)
  //   cout << v << " ";
  // cout << endl;
  long long best = 1e18;
  long long aa, bb;
  int n = sz(pr);
  for(int mask = 0 ; mask < (1 << n) ; mask++){
    long long a = 1, b = 1;
    for(int i = 0 ; i < n ; i++){
      if(mask & (1 << i)) a *= pr[i];
      else b *= pr[i];
    }
    // cout << a << " " << b << endl;
    if(best > max(a, b)){
      best = max(a, b);
      aa = a, bb = b;
    }
  }
  cout << aa << " " << bb << endl;
  return 0;
}
