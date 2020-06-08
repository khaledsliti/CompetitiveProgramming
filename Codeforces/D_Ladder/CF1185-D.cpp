// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;

int n;
pair<int, int> arr[N];
int L[N], R[N];

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    arr[i] = {x, i};
  }
  sort(arr + 1, arr + n + 1);
  if(n < 4) { 
    cout << 1 << endl;
    return 0;
  }
  L[0] = L[1] = L[2] = 1;
  for(int i = 3; i <= n; i++) {
    if(arr[i - 1].first - arr[i - 2].first == arr[i].first - arr[i - 1].first) L[i] = 1;
    else break;
  }
  R[n + 1] = R[n] = R[n - 1] = 1;
  for(int i = n - 2; i > 0; i--) {
    if(arr[i + 1].first - arr[i].first == arr[i + 2].first - arr[i + 1].first) R[i] = 1;
    else break;
  }
  
  int index = -1;
  for(int i = 1; i <= n && index == -1; i++) {
    if(L[i - 1] && R[i + 1]) {
      if(i == 1 || i == n) index = arr[i].second;
      else {
        int d = arr[i + 1].first - arr[i - 1].first;
        if((i <= 2 || arr[2].first - arr[1].first == d) && (i >= n - 1 || arr[n].first - arr[n - 1].first == d))
          index = arr[i].second;
      }
    }
  }
  cout << index << endl;
  return 0;
}
