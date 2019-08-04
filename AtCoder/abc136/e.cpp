#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int N = 502;

int n, k;
int arr[N];

bool check(int a)
{
  deque<int> v;
  for(int i = 0 ; i < n ; i++){
    int r = arr[i] % a;
    if(r){
      v.push_back(r);
    }
  }
  sort(rall(v));
  int cnt = 0;
  while(sz(v)){
    int x = v.front();
    int y = v.back();
    int z = a - x;
    if(z > y){
      v.front() += v.back();
      cnt += v.back();
      v.pop_back();
    }else{
      v.pop_front();
      v.back() -= z;
      cnt += z;
      if(!v.back())
        v.pop_back();
    }
  }
  return cnt <= k;
}

int main()
{
  while(cin >> n >> k){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
      cin >> arr[i];
      sum += arr[i];
    }
    int ans = 1;
    for(int cur = 1 ; cur * cur <= sum ; cur++){
      if(sum % cur == 0){
        if(check(cur) && cur > ans)
          ans = cur;
        int d = sum / cur;
        if(d != cur && check(d) && d > ans)
          ans = d;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
