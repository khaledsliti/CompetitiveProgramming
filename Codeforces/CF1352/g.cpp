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

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    if(n % 4 <= 1) {
      for(int st = 1; st < n; st += 4)
        cout << st + 1 << " " << st + 3 << " " << st << " " << st + 2 << " ";
      if(n % 4) cout << n;
      cout << endl;
    } else if(n % 4 == 2) {
      int k = n - 6;
      if(k < 0) {
        cout << -1 << endl;
      } else {
        int st = 1;
        for(; st <= k; st += 4)
          cout << st + 1 << " " << st + 3 << " " << st << " " << st + 2 << " ";
        cout << st << " " << st + 2 << " " << st + 4 << " " << st + 1 << " " << st + 3 << " " << st + 5 << endl;
      }
    } else {
      int k = n - 7;
      if(k < 0) {
        cout << -1 << endl;
      } else {
        int st = 1;
        for(; st <= k; st += 4)
          cout << st + 1 << " " << st + 3 << " " << st << " " << st + 2 << " ";
        vector<int> idx = {0, 2, 6, 4, 1, 3, 5};
        for(int i = 0 ; i < sz(idx); i++)
          cout << st + idx[i] << " ";
        cout << endl;
      }
    }
  }
  return 0;
}
