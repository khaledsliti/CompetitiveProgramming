#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 3e5 + 6;

int n, m;
int arr[N];

bool check(int len)
{
  int soFar = 1e9;
  for(int i = n - 1 ; i >= 0 ; i--){
    if(arr[i] > soFar){
      if(arr[i] + len < m)
        return false;
      int cur = (arr[i] + len) % m;
      if(cur > soFar)
        cur = soFar;
      soFar = cur;
    }else{
      soFar = min(soFar, min(m - 1, arr[i] + len));
    }
  }
  return true;
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", &arr[i]);
  }
  int l = 0, r = m, ans = m;
  while(l <= r){
    int mid = (l + r) / 2;
    if(check(mid)){
      ans = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}