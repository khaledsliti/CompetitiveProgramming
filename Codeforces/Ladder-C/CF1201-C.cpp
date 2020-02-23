#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;
int arr[N];

bool check(int val)
{
  long long ans = 0;
  for(int i = n / 2 ; i < n ; i++){
    ans += max(0, val - arr[i]);
  }
  return ans <= k;
}

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  sort(arr, arr + n);
  int l = arr[n >> 2], r = 2e9, ans = arr[n >> 1];
  while(l <= r){
    int mid = l + (r - l) / 2;
    if(check(mid)){
      ans = mid;
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
