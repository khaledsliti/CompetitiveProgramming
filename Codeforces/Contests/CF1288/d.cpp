#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 3e5 + 5;
const int M = 8;

int n, m;
int arr[N][M];

bool check(int mn, int& idx1, int& idx2)
{
  vector<int> idx(1 << m, -1);
  for(int i = 0 ; i < n ; i++){
    int msk = 0;
    for(int j = 0 ; j < m ; j++)
      if(arr[i][j] >= mn)
        msk |= (1 << j);
    idx[msk] = i;
  }
  for(int i = 1 ; i < (1 << m) ; i++)
    for(int j = 1 ; j < (1 << m) ; j++)
      if(~idx[i] && ~idx[j] && (i | j) == (1 << m) - 1){
        idx1 = idx[i] + 1;
        idx2 = idx[j] + 1;
        return true;
      }
  return false;
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++)
      scanf("%d", &arr[i][j]);
  }
  int l = 0, r = 1e9, ans = 0, idx1, idx2;
  while(l <= r){
    int mid = (l + r) / 2;
    if(check(mid, idx1, idx2)){
      ans = mid;
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  cout << idx1 << " " << idx2 << endl;
  return 0;
}
