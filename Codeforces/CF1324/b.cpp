// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5005;

int n;
int arr[N];

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
      cin >> arr[i];
    }
    bool yes = false;
    for(int i = 0 ; i < n && !yes; i++) {
      for(int j = i + 2 ; j < n && !yes ; j++) {
        yes = arr[i] == arr[j];
      }
    }
    cout << (yes ? "YES" : "NO") << endl;
  }
  return 0;
}
