#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n;
int arr[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long ans = 0;
  for(int i = 0 ; i < n / 2 ; i++){
    ans += 1LL * (arr[i] + arr[n - 1 - i]) * (arr[i] + arr[n - 1 - i]);
  }
  cout << ans << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity