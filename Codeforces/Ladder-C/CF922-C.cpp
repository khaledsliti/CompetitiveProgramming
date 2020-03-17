// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  long long n, k;
  cin >> n >> k;
  for(long long i = 1 ; i <= k ; i++) {
    if((n + 1) % i != 0)
      return cout << "No" << endl, 0;
  }
  cout << "Yes" << endl;
  return 0;
}
