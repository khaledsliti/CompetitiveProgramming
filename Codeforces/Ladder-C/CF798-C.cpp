// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int arr[N];

int main()
{
  cin >> n;
  int g = 0;
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
    g = __gcd(g, arr[i]);
  }
  cout << "YES\n";
  if(g > 1)
    cout << 0 << endl;
  else {
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
      if(arr[i] & 1) {
        int j = i;
        while(j < n && arr[j] & 1)
          ++j;
        --j;
        int len = j - i + 1;
        ans += len / 2;
        if(len & 1) ans += 2;
        i = j;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
