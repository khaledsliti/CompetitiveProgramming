// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n;
int lA, rA, lB, rB, l, r;
char A[N], B[N];
char ans[N];

int main()
{
  scanf("%s%s", A, B);
  n = strlen(A);
  sort(A, A + n);
  sort(B, B + n);
  int lA = 0, rA = (n + 1) / 2 - 1;
  int lB = (n - 1) / 2 + 1, rB = n - 1;
  int l = 0, r = n - 1, p = 0;
  while(l <= r) {
    if(B[rB] <= A[lA])
      ans[r--] = p ? B[lB++] : A[rA--];
    else
      ans[l++] = p ? B[rB--] : A[lA++];
    p ^= 1;
  }
  for(int i = 0 ; i < n ; i++)
    printf("%c", ans[i]);
  return 0;
}
