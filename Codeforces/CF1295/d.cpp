#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long solve(long long n)
{
  long long phi = n;
  for(long long i = 2 ; i * i <= n ; i++){
    if(n % i == 0){
      phi = phi / i * (i - 1);
      while(n % i == 0)
        n /= i;
    }
  }
  if(n > 1)
    phi = phi / n * (n - 1);
  return phi;
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    long long a, m;
    cin >> a >> m;
    cout << solve(m / __gcd(a, m)) << endl;
  }
  return 0;
}
