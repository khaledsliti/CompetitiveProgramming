#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5;

int n;
int arr[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  unordered_map<int, int> pref;
  pref[0] = 1;
  int sum = 0;
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    sum ^= arr[i];
    ans += pref[sum];
    pref[sum]++;
  }
  cout << ans << endl;
  return 0;
}
