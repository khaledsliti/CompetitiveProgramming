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

const int N = 8001;

int n;
int arr[N];
int fr[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++)
      scanf("%d", arr + i);
    for(int i = 1 ; i <= n ; i++)
      fr[i] = 0;
    for(int i = 0 ; i < n ; i++) {
      int s = arr[i];
      for(int j = i + 1; j < n && s <= n; j++) {
        s += arr[j];
        if(s <= n)
          fr[s]++;
      }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
      if(fr[arr[i]])
        ans++;
    printf("%d\n", ans);
  }
  return 0;
}
