#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 55;

int n;
vector<pair<int, int>> arr;
int done[N];


int solve(int p, int q)
{
  for(int i = 0 ; i < n ; i++){
    done[i] = false;
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    if(!done[i]){
      ans++;
      done[i] = true;
      pair<int, int> last = arr[i];
      for(int j = 0 ; j < n ; j++)
        if(!done[j] && last.first + p == arr[j].first && last.second + q == arr[j].second){
          done[j] = true;
          last = arr[j];
        }
    }
  }
  return ans;
}

int main()
{
  while(cin >> n){
    set<pair<int, int>> st;
    for(int i = 0 ; i < n ; i++){
      int x, y;
      cin >> x >> y;
      st.insert({x, y});
    }
    if(n == 1){
      cout << 1 << endl;
      continue;
    }
    arr.clear();
    for(auto p : st)
      arr.pb(p);
    sort(all(arr));
    // for(auto x : arr)
    //   cout << x.first << " " << x.second << endl;
    int ans = 1e9;
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        if(i != j && arr[i].first <= arr[j].first){
          ans = min(ans, solve(arr[j].first - arr[i].first, arr[j].second - arr[i].second));
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
