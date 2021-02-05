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

const int N = 1008;

int n;
int arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    int x = 0;
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
      x += arr[i];
    }
    int y = n - x;
    if(n == 2) {
      if(arr[0] == 1 && arr[1] == 1) {
        cout << 2 << endl << "1 1\n";
      } else {
        cout << 1 << endl;
        cout << "0" << endl;
      }
    } else if(x > y) {
      if(x & 1) x--;
      cout << x << endl;
      for(int i = 0; i < x; i++) 
        cout << 1 << " ";
      cout << endl;
    } else {
      cout << y << endl;
      for(int i = 0; i < y; i++) 
        cout << 0 << " ";
      cout << endl;
    }
  }
  return 0;
}
