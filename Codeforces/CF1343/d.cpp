#include <bits/stdc++.h>
using namespace std;

int const maxN = 400010;

int n, k;
int arr[maxN];
int acc[maxN];

void add(int l, int r, int val) {
  if(l > r) return;
  acc[l] += val;
  if(r + 1 <= 2 * k)
    acc[r + 1] -= val;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
      scanf("%d", &arr[i]);
    }
    for(int i = 0 ; i <= 2 * k; i++)
      acc[i] = 0;
    for(int i = 0 ; i < n / 2 ; i++) {
      int a = arr[i], b = arr[n - 1 - i];
      if(a > b) swap(a, b);
      add(2, a, 2);
      add(a + 1, a + b - 1, 1);
      add(a + b + 1, b + k, 1);
      add(b + k + 1, 2 * k, 2);
    }
    for(int i = 1 ; i <= 2 * k ; i++)
      acc[i] += acc[i - 1];
    int best = 2;
    for(int i = 3 ; i <= 2 * k ; i++)
      if(acc[best] > acc[i])
        best = i;
    printf("%d\n", acc[best]);
  }
  return 0;
}
