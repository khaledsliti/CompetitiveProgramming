// Guess Who's Back
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

const int N = 1007;

int n;
int arr[N];

void solve(int l, int r) {
  int sum = 0;
  for(int i = l; i <= r; i++) {
    sum += arr[i];
  }
  int bestIndex = -1, bestLeftSum, bestDiff, curLeftSum = 0;
  for(int i = l; i <= r; i++) {
    if(i + 1 > r || arr[i] != arr[i + 1]) {
      int curRightSum = sum - curLeftSum - arr[i];
      int curDiff = abs(curLeftSum - curRightSum);
      if(bestIndex == -1 || bestDiff > curDiff || bestDiff == curDiff && curLeftSum > bestLeftSum) {
        bestIndex = i;
        bestDiff = curDiff;
        bestLeftSum = curLeftSum;
      }
    }
    curLeftSum += arr[i];
  }
  printf("%d", arr[bestIndex]);
  if(l < r) printf("(");
  if(bestIndex > l) solve(l, bestIndex - 1);
  if(bestIndex > l && bestIndex < r) printf(",");
  if(bestIndex < r) solve(bestIndex + 1, r);
  if(l < r) printf(")");
}

void solve(int test) {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  printf("Case #%d: ", test);
  solve(0, n - 1);
  printf("\n");
}

int main()
{
  int tests;
  scanf("%d", &tests);
  for(int test = 1; test <= tests; test++) {
    solve(test);
  }
  return 0;
}
