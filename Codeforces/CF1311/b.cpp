// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100;

int n, m;
int arr[N];
int p[N];

int main()
{
  int t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
      cin >> arr[i];
      p[i] = i;
    }
    while(m--){
      int x;
      cin >> x;
      p[x - 1] = x;
    }
    for(int i = n - 1 ; i >= 0 ; i--){
      p[i] = p[p[i]];
    }
    // for(int i = 0 ; i < n ;i++)
    //   cout << p[i] << " ";
    // cout << endl;
    for(int i = 0 ; i < n ; i++){
      int j = p[i];
      sort(arr + i, arr + j + 1);
      i = j;
    }
    // for(int i = 0 ; i < n ;i++)
    //   cout << arr[i] << " ";
    // cout << endl;
    bool s = true;
    for(int i = 1 ; i < n ; i++)
      if(arr[i] < arr[i - 1])
        s = false;
    if(s) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
