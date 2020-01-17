#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//Constants
const int N = 1e5 + 5;

//Data
int n, m;
int arr[N];

//Methods
long long lcm(long long a, long long b)
{
  return a / __gcd(a, b) * b;
}

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
    arr[i] >>= 1;
  }
  long long cur = arr[0];
  for(int i = 1 ; i < n ; i++){
    cur = lcm(cur, arr[i]);
    if(cur > m)
      return cout << 0 << endl, 0;
  }
  for(int i = 0 ; i < n ; i++){
    if((cur / arr[i]) % 2 == 0)
      return cout << 0 << endl, 0;
  }
  cout << (m / cur + 1) / 2 << endl;
  return 0;
}
