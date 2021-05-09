// Guess Who's Back
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;



int main()
{
  long long n, k;
  cin >> n >> k;
  while(k--) {
    if(n % 200 == 0) n /= 200;
    else n = n * 1000 + 200;
  }
  cout << n << endl;
  return 0;
}
