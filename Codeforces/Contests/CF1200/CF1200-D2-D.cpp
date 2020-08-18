#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2005;

int n, k;
char s[N];
int arr[N][N];
pair<int, int> R[N], C[N];
int cntC[N][N];
int cntR[N][N];
int pr[N], pc[N];

int get(int* p, int i, int j)
{
  if(i > j)
    return 0;
  return p[j] - (i > 0 ? p[i - 1] : 0);
}

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++){
    scanf("%s", s);
    for(int j = 0 ; j < n ; j++)
      arr[i][j] = s[j] == 'B';
  }
  // for(int i = 0 ; i < n ; i++){
  //   for(int j = 0 ; j < n ; j++)
  //     cout << arr[i][j];
  //   cout << endl;
  // }
  for(int i = 0 ; i < n ; i++){
    int mn = n, mx = -1;
    for(int j = 0 ; j < n ; j++){
      if(arr[i][j]){
        mn = min(mn, j);
        mx = max(mx, j);
      }
    }
    R[i] = { mn, mx };
    if(mn == n)
      pr[i] = 1;
  }
  for(int j = 0 ; j < n ; j++){
    int mn = n, mx = -1;
    for(int i = 0 ; i < n ; i++){
      if(arr[i][j]){
        mn = min(mn, i);
        mx = max(mx, i);
      }
    }
    C[j] = { mn, mx };
    if(mn == n)
      pc[j] = 1;
  }
  for(int i = 1 ; i < n ; i++){
    pr[i] += pr[i - 1];
    pc[i] += pc[i - 1];
  }
  // for(int i = 0 ; i < n ; i++)
  //   cout << pr[i] << " ";
  // cout << endl;
  // for(int i = 0 ; i < n ; i++)
  //   cout << pc[i] << " ";
  // cout << endl;
  // exit(0);
  memset(cntC, -1, sizeof cntC);
  memset(cntR, -1, sizeof cntR);
  for(int j = 0 ; j + k - 1 < n ; j++){
    int lc = j, rc = j + k - 1;
    int cur = 0;
    for(int i = 0 ; i < n ; i++){
      if(R[i].first >= lc && R[i].second <= rc){
        cur++;
      }
      if(i - k >= 0 && R[i - k].first >= lc && R[i - k].second <= rc){
        cur--;
      }
      if(i - k + 1 >= 0)
        cntR[i - k + 1][j] = cur + get(pr, i + 1, n - 1) + get(pr, 0, i - k);
    }
  }
  // for(int i = 0 ; i < n ; i++){
  //   for(int j = 0 ; j < n ; j++)
  //     cout << cntR[i][j] << " ";
  //   cout << endl;
  // }
  for(int i = 0 ; i + k - 1 < n ; i++){
    int lr = i, rr = i + k - 1;
    int cur = 0;
    for(int j = 0 ; j < n ; j++){
      if(C[j].first >= lr && C[j].second <= rr){
        cur++;
      }
      if(j - k >= 0 && C[j - k].first >= lr && C[j - k].second <= rr){
        cur--;
      }
      if(j - k + 1 >= 0)
        cntC[i][j - k + 1] = cur + get(pc, j + 1, n - 1) + get(pc, 0, j - k);
    }
  }
  // cout << "----\n";
  // for(int i = 0 ; i < n ; i++){
  //   for(int j = 0 ; j < n ; j++)
  //     cout << cntC[i][j] << " ";
  //   cout << endl;
  // }
  int ans = 0;
  for(int i = 0 ; i + k - 1 < n ; i++)
    for(int j = 0 ; j + k - 1 < n ; j++)
      ans = max(ans, cntC[i][j] + cntR[i][j]);
  cout << ans << endl;
  return 0;
}