#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, m;
pair<int, int> arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr, arr + n);
  int j = 0, len = 1;
  priority_queue<int> pq;
  int ans = 0;
  for(int i = m - 1 ; i >= 0 ; i--){
    while(j < n && arr[j].first <= len){
      pq.push(arr[j].second);
      j++;
    }
    if(!pq.empty()){
      int t = pq.top();
      pq.pop();
      ans += t;
    }
    len++;
  }
  cout << ans << endl;
  return 0;
}
