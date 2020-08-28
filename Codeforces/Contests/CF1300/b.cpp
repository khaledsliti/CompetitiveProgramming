#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int arr[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    n *= 2;
    for(int i = 0 ; i < n ; i++)
      scanf("%d", arr + i);
    sort(arr, arr + n);
    printf("%d\n", arr[n / 2] - arr[n / 2 - 1]);
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity