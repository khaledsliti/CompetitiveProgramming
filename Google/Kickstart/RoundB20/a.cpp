// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()



int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for(int i = 1 ; i < n - 1 ; i++)
      if(a[i] > a[i - 1] && a[i] > a[i + 1])
        ans++;
    cout << "Case #" << tc++ << ": " << ans << endl;
  }
  return 0;
}
