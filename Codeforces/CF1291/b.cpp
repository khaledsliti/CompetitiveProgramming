#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n;
int arr[N], tmp[N];
int L[N], R[N];

bool solve()
{
  for(int i = 0 ; i < n ; i++)
    L[i] = R[i] = 2e9;
  for(int i = 0 ; i < n ; i++){
    if(arr[i] >= i)
      L[i] = i;
    else
      break;
  }
  for(int i = n - 1, j = 0 ; i >= 0 ; i--, j++)
    if(arr[i] >= j)
      R[i] = j;
    else
      break;
  // for(int i = 0 ; i < n ; i++)
  //   cout << L[i] << " ";
  // cout << endl;
  // for(int i = 0 ; i < n ; i++)
  //   cout << R[i] << " ";
  // cout << endl;
  for(int i = 0 ; i < n ; i++){
    if((i == 0 || arr[i] > L[i - 1]) && (i == n - 1 || arr[i] > R[i + 1]))
      return 1;
  }
  return 0;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
      scanf("%d", arr + i);
    }
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity