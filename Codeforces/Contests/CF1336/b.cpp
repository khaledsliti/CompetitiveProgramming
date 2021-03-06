// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100007;

int a, b, c;
int A[N], B[N], C[N];

int get_after(int* arr, int n, int val) {
  int idx = lower_bound(arr, arr + n, val) - arr;
  if(idx >= n) return -1;
  return arr[idx];
}

int get_before(int* arr, int n, int val) {
  int idx = lower_bound(arr, arr + n, val + 1) - arr - 1;
  if(idx < 0) return -1;
  return arr[idx];
}

long long get(long long a, long long b, long long c) {
  return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d%d", &a, &b, &c);
    for(int i = 0 ; i < a ; i++)
      scanf("%d", A + i);
    for(int i = 0 ; i < b ; i++)
      scanf("%d", B + i);
    for(int i = 0 ; i < c ; i++)
      scanf("%d", C + i);
    sort(A, A + a);
    sort(B, B + b);
    sort(C, C + c);
    long long best = 4e18;
    for(int i = 0 ; i < a ; i++) {
      int x = A[i];
      int y = get_after(B, b, x);
      int z = get_before(C, c, x);
      if(y != -1 && z != -1)
        best = min(best, get(x, y, z));
      y = get_before(B, b, x);
      z = get_after(C, c, x);
      if(y != -1 && z != -1)
        best = min(best, get(x, y, z));
    }
    for(int i = 0 ; i < b ; i++) {
      int x = B[i];
      int y = get_after(C, c, x);
      int z = get_before(A, a, x);
      if(y != -1 && z != -1)
        best = min(best, get(x, y, z));
      y = get_before(C, c, x);
      z = get_after(A, a, x);
      if(y != -1 && z != -1)
        best = min(best, get(x, y, z));
    }
    for(int i = 0 ; i < c ; i++) {
      int x = C[i];
      int y = get_after(A, a, x);
      int z = get_before(B, b, x);
      if(y != -1 && z != -1)
        best = min(best, get(x, y, z));
      y = get_before(A, a, x);
      z = get_after(B, b, x);
      if(y != -1 && z != -1)
        best = min(best, get(x, y, z));
    }
    cout << best << endl;
  }
  return 0;
}
