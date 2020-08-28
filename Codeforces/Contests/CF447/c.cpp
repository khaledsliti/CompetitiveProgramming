#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5;

int n;
int arr[N];
int L[N], R[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  R[n - 1] = 1;
  for(int i = n - 2 ; i >= 0 ; i--){
    R[i] = 1;
    if(arr[i] < arr[i + 1])
      R[i] = 1 + R[i + 1];
  }
  L[0] = 1;
  for(int i = 1 ; i < n ; i++){
    L[i] = 1;
    if(arr[i] > arr[i - 1])
      L[i] = 1 + L[i - 1];
  }
  int ans = 1;
  for(int i = 0 ; i < n ; i++){
    int cur = 1;
    if(i + 1 < n)
      ans = max(ans, 1 + R[i + 1]);
    if(i - 1 >= 0)
      ans = max(ans, 1 + L[i - 1]);
    if(i + 1 < n && i - 1 >= 0 && arr[i - 1] + 1 < arr[i + 1])
      ans = max(ans, L[i - 1] + 1 + R[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
