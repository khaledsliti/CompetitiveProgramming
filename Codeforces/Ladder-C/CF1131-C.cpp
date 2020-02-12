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
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int i = 0;
  while(i < n){
    cout << arr[i] << " ";
    i += 2;
  }
  i -= 2;
  if(n & 1) i--;
  else i++;
  while(i >= 0){
    cout << arr[i] << " ";
    i -= 2;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity