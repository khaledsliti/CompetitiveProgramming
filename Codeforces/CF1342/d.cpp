// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;
int arr[N], c[N];
vector<vector<int>> sol;

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    int a; scanf("%d", &a);
    arr[a]++;
  }
  for(int i = 1 ; i <= k ; i++)
    scanf("%d", &c[i]);
  int At = 0;
  for(int i = N - 1 ; i > 0 ; i--) {
    while(At > 0 && sz(sol[At - 1]) < c[i])
      At--;
    for(int j = 0 ; j < arr[i] ; j++) {
      while(At < sz(sol) && sz(sol[At]) >= c[i])
        At++;
      if(At >= sz(sol))
        sol.push_back(vector<int>());
      sol[At].pb(i);
    }
  }
  printf("%d\n", sz(sol));
  for(int i = 0 ; i < sz(sol) ; i++) {
    printf("%d", sz(sol[i]));
    for(int x : sol[i])
      printf(" %d", x);
    printf("\n");
  }
  return 0;
}
