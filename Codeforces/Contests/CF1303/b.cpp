#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long get(int n, long long a, long long b, long long q)
{

}

long long solve()

bool check(long long n, long long a, long long b, long long q)
{

}

int main()
{
  int t;
  cin >> t;
  while(t--){
    long long n, a, b;
    cin >> n >> a >> b;
    long long lo = 0, hi = 1e18, mn;
    while(lo <= hi){
      long long mid = lo + (hi - lo) / 2;
      if(check(n, a, b, mid)){
        mn = hi;
        hi = mid - 1;
      }else{
        lo = mid + 1;
      }
    }
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity