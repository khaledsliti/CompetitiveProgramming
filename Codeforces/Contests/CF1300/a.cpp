#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 101;

int n;
int arr[N];

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    int cnt = 0;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
      cin >> arr[i];
      if(arr[i] == 0){
        cnt++;
        arr[i] = 1;
      }
      sum += arr[i];
    }
    if(sum == 0)
      cnt++;
    cout << cnt << endl;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity