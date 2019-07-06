#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 2;

int n;
long long k;
long long arr[N];

long long get(int i, int j)
{
  long long r = arr[j];
  if(i) r -= arr[i - 1];
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
    if(i) arr[i] += arr[i - 1];
  }
  long long ans = 0;
  for(int i = 0 ; i < n ; i++){
    int l = 0, r = i, idx = -1;
    while(l <= r){
      int mid = (l + r) / 2;
      if(get(mid, i) >= k){
        idx = mid;
        l = mid + 1;
      }else{
        r = mid - 1;
      }
    }
    ans += idx + 1;
  }
  cout << ans << endl;
  return 0;
}
