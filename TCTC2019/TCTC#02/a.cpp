#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5;

int n;
int arr[N];
int hate[N];
long long ans[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }
  string line;
  for(int i = 0 ; i < n ; i++){
    cin >> line;
    for(int j = 0 ; j < 7 ; j++)
      if(line[j] == '1')
        hate[i] |= (1 << j);
  }
  for(int mask = 0 ; mask < (1 << 7) ; ++mask){
    long long cur = 0;
    for(int i = 0 ; i < n ; i++)
      if(!(mask & hate[i]))
        cur += arr[i];
    int cnt = __builtin_popcount(mask);
    ans[cnt] = max(ans[cnt], cur);
  }
  for(int i = 1 ; i <= 7 ; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
