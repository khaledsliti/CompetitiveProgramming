#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, k;
char s[N];
vector<int> pos[2];

int main()
{
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  for(int i = 0 ; i < n ; i++)
    pos[s[i] - '0'].push_back(i);
  for(int t = 0 ; t < 2 ; t++){
    vector<int>& v = pos[t];
    if(v.empty() || v.back() - v.front() < k)
      return cout << "tokitsukaze" << endl, 0;
  }
  for(int i = 0 ; i + k <= n ; i++){
    for(int t = 0 ; t < 2 ; t++){
      vector<int>& v = pos[t];
      int first = i, last = i + k - 1;
      if(v.front() < first && v.back() > last){
        return cout << "once again" << endl, 0;
      }else if(v.front() < first){
        int idx = lower_bound(all(v), first) - v.begin() - 1;
        if(v[idx] - v.front() >= k){
          return cout << "once again" << endl, 0;
        }
      }else{
        int idx = lower_bound(all(v), last + 1) - v.begin();
        if(v.back() - v[idx] >= k){
          return cout << "once again" << endl, 0;
        }
      }
    }
  }
  cout << "quailty" << endl;
  return 0;
}
