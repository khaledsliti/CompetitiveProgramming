// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;



int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
      cin >> a[i];
    for(int i = 0 ; i < n; i++) {
      if(i & 1) a[i] = abs(a[i]);
      else a[i] = -abs(a[i]);
    }
    for(int i = 0; i < n; i++)
      cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
