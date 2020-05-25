// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 50;

int n, arr[N];

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
      if(arr[i] & 1)
        odd++;
      else even++;
    }
    if(odd & 1) {
      sort(arr, arr + n);
      bool f = 0;
      for(int i = 1; i < n; i++)
        if(arr[i] == arr[i - 1] + 1)
          f = true;
      D(f);
      if(f) cout << "YES" << endl;
      else cout << "NO" << endl;
    }else cout << "YES" << endl;
  }
  return 0;
}
