#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k;
int arr[N];
int pref_min[N];

bool check_pref(int sum) {
  return sum >= 1;
}

bool check(int mid) {
  int pref = 0;
  for(int i = 0; i < n; i++) {
    int v = (arr[i] >= mid) ? 1 : -1;
    pref += v;
    if(i >= k - 1) {
      if(check_pref(pref)) {
        return true; 
      }
      if(i - k >= 0) {
        int mn = pref_min[i - k];
        if(check_pref(pref - mn)) {
          return true; 
        }
      }
    }
    pref_min[i] = pref;
    if(i > 0) {
      pref_min[i] = min(pref_min[i], pref_min[i - 1]);
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]); 
  }
  int lo = n, hi = 1, ans;
  for(int i = 0; i < n; i++) {
    lo = min(lo, arr[i]);
    hi = max(hi, arr[i]);
  }
  
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1; 
    }
  }
  printf("%d\n", ans);
}
