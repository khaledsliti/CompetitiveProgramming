// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, arr[N];

bool solve() {
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  for(int i = n - 1 ; i >= 0 ; i--) {
    int j = i - 1;
    while(j >= 0 && arr[j] < arr[j + 1]) {
      --j;
    }
    reverse(arr + j + 1, arr + i + 1);
    i = j + 1;
  }
  for(int i = 0 ; i + 1 < n ; i++)
    if(arr[i] < arr[i + 1])
      return false;
  return true;
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    printf("%s\n", solve() ? "Yes" : "No");
  }
  return 0;
}
