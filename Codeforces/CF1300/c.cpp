#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int arr[N];
int L[N], R[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", arr + i);
  }
  L[0] = arr[0];
  for(int i = 1 ; i < n ; i++){
    L[i] = L[i - 1] | arr[i];
  }
  R[n - 1] = arr[n - 1];
  for(int i = n - 2 ; i >= 0 ; i--){
    R[i] = R[i + 1] | arr[i];
  }
  int best = -1;
  int At;
  for(int i = 0 ; i < n ; i++){
    int l = i > 0 ? L[i - 1] : 0;
    int r = i < n - 1 ? R[i + 1] : 0;
    int cur = (arr[i] | (l | r)) - (l | r);
    if(cur > best){
      best = cur;
      At = i;
    }
  }
  cout << arr[At];
  for(int i = 0 ; i < n ; i++)
    if(i != At)
      cout << " " << arr[i];
  cout << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity