#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 305;

int n;
int arr[N][N];

int main()
{
  cin >> n;
  int cur = 1;
  for(int j = 0 ; j < n ; j++){
    if(j & 1)
      for(int i = n - 1 ; i >= 0 ; i--)
        arr[i][j] = cur++;
    else
      for(int i = 0 ; i < n ; i++)
        arr[i][j] = cur++;
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  return 0;
}
