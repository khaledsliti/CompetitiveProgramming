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

const int N = 1005;

int n;
int arr[N];
int mn[N];

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    mn[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--) {
      if(arr[i] < arr[mn[i + 1]]) mn[i] = i;
      else mn[i] = mn[i + 1];
    }
    bool yes = false;
    for(int i = 0; i < n && !yes; i++) {
      for(int j = i + 1; j + 1 < n && !yes; j++) {
        if(arr[i] < arr[j] && arr[mn[j + 1]] < arr[j]) {
          yes = true;
          cout << "YES" << endl;
          cout << i + 1 << " " << j + 1 << " " << mn[j + 1] + 1 << endl;
        }
      }
    }
    if(!yes) cout << "NO" << endl;
  }
  return 0;
}
