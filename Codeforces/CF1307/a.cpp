#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;

int n, d;
int arr[N];

int main()
{
  int t;
  cin >> t;
  while(t--){
    cin >> n >> d;
    for(int i = 0 ; i < n ; i++){
      cin >> arr[i];
    }
    for(int i = 1 ; i < n ; i++){
      while(d >= i && arr[i] > 0)
        arr[0]++, arr[i]--, d -= i;
    }
    cout << arr[0] << endl;
  }
  return 0;
}
