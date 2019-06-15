#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 4;

int n;
int arr[N], sum[N];
vector<pair<int, int>> sol;

int add(int x, int y)
{
  sol.push_back({x, y});
  return x - y;
}

int main()
{
  while(scanf("%d", &n) != EOF){
    for(int i = 0 ; i < n ; i++)
      scanf("%d", arr + i);
    sort(arr, arr + n);
    int idx = 0;
    if(arr[0] >= 0) idx = 0;
    else if (arr[n - 1] < 0) idx = n - 2;
    else
      for(int i = 0 ; i + 1 < n ; i++)
        if(arr[i] * arr[i + 1] <= 0){
          idx = i;
          break;
        }
    sol.clear();
    int soFar = arr[0];
    for(int i = idx + 1 ; i + 1 < n ; i++)
      soFar = add(soFar, arr[i]);
    soFar = add(arr[n - 1], soFar);
    for(int i = 1 ; i <= idx ; i++)
      soFar = add(soFar, arr[i]);
    cout << soFar << endl;
    for(auto x: sol)
      cout << x.first << " " << x.second << endl;
  }
  return 0;
}
