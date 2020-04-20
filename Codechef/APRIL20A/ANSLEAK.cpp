// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 501;
const int K = 5001;
const int INF = 1e9;

int n, k, m;
int arr[K][N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < k ; j++)
        scanf("%d", &arr[j][i]);
    for(int i = 0 ; i < n ; i++)
      printf("%d%c", rand() % 2 + 1, " \n"[i == n - 1]);
  }
  return 0;
}
