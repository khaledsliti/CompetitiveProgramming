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

const int N = 5005;

int n;
int arr[N];

int main()
{
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0 ; i < n ; i++)
      cin >> arr[i];
    int l = 0, r = n - 1;
    int a = 0, b = 0, ta = 0, tb = 0;
    int tot = 0, alice = 1;
    while(l <= r) {
      tot++;
      if(alice) {
        a = 0;
        while(l <= r && a <= b) {
          a += arr[l++];
        }
        ta += a;
      } else {
        b = 0;
        while(r >= l && a >= b) {
          b += arr[r--];
        }
        tb += b;
      }
      alice ^= 1;
    }
    cout << tot << " " << ta << " " << tb << endl;
  }
  return 0;
}
