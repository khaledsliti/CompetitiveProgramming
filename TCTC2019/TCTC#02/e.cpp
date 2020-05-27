#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 2e5 + 5;

int n;
int arr[N];
int v[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  int len = 1;
  v[0] =  arr[0];
  for(int i = 1 ; i < n ; i++){
    int idx = lower_bound(v, v + len, arr[i]) - v;
    v[idx] = arr[i];
    if(idx == len)
      len++;
  }
  cout << len << endl;
  return 0;
}
