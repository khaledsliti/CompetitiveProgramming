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

const int N = 2e5 + 5;

int arr[] = { 6, 10, 14, 15, 21, 22 };

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    bool good = false;
    for(int i = 0; i < 6 && !good; i++) {
      for(int j = i + 1; j < 6 && !good; j++) {
        for(int k = j + 1; k < 6 && !good; k++) {
          int s = arr[i] + arr[j] + arr[k];
          if(s < n && n - s != arr[i] && n - s != arr[j] && n - s != arr[k]) {
            cout << "YES" << endl;
            cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << n - s << endl;
            good = true;
          }
        }
      }
    }
    if(!good)
      cout << "NO" << endl;
  }
  return 0;
}
