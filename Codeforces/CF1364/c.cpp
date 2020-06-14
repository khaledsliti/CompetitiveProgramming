// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 100005;

int n;
int arr[N];
int sol[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", arr + i);
  memset(sol, -1, sizeof sol);
  int cur_mex = 0;
  vector<int> big;
  for(int i = 0; i < n; i++) {
    if(arr[i] < cur_mex) {
      cout << -1 << endl;
      return 0;
    }
    if(arr[i] == cur_mex) {
      big.push_back(i);
      continue;
    }
    big.push_back(i);
    while(sz(big) > 0 && cur_mex < arr[i]) {
      int idx = big.back();
      sol[idx] = cur_mex++;
      big.pop_back();
    }
    if(cur_mex < arr[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  for(int i = 0; i < n; i++)
    if(sol[i] == -1)
      sol[i] = 1e6;
  for(int i = 0; i < n; i++)
    printf("%d ", sol[i]);
  printf("\n");
  return 0;
}
