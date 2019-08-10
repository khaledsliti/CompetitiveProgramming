#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;
long long arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long cnt = 1, cur = arr[n / 2];
  for(int i = n / 2 + 1; i < n ; i++){
    long long dif = arr[i] - arr[i - 1];
    long long need = dif * cnt;
    if(k >= need){
      k -= need;
      cur = arr[i];
      cnt++;
    }else{
      break;
    }
  }
  cur += k / cnt;
  cout << cur << endl;
  return 0;
}
