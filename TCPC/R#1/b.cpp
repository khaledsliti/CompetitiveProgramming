#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5;

int n;
int arr[N];
int nxt[N];
unordered_map<int, int> last;

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", arr + i);
    last[arr[i]] = n;
  }
  for(int i = n - 1 ; i >= 0 ; i--){
    nxt[i] = last[arr[i]];
    last[arr[i]] = i;
  }
  int right = 0;
  for(auto& x : last)
    right = max(right, x.second);
  int best = right + 1;
  for(int i = 0 ; i < n - 1 ; i++){
    if(nxt[i] == n)
      break;
    right = max(right, nxt[i]);
    best = min(best, right - i);
  }
  cout << best << endl;
  return 0;
}
