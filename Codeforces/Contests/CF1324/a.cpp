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
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
      cin >> arr[i];
    bool ok = true;
    for(int i = 0 ; i < n ; i++)
      ok &= (arr[0] & 1) == (arr[i] & 1);
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
