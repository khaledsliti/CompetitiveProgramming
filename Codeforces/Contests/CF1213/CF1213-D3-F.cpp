#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;
int a[N], b[N];
int idx[N];
int ans[N];

int ncomp;
vector<int> comp[N];
int compOf[N];

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", a + i);
    idx[--a[i]] = i;
  }
  vector<pair<int, int>> eq;
  for(int i = 0 ; i < n ; i++){
    scanf("%d", b + i);
    b[i]--;
    if(i){
      int idx1 = idx[b[i - 1]];
      int idx2 = idx[b[i]];
      if(idx1 > idx2)
        eq.push_back({idx2, idx1});
    }
  }
  // for(auto x : eq)
  //   cout << x.first << " " << x.second << endl;
  sort(all(eq));
  memset(compOf, -1, sizeof compOf);
  int cur = 0;
  for(int i = 0 ; i < sz(eq) ;){
    int left = eq[i].first;
    int right = eq[i].second;
    while(i < sz(eq) && right >= eq[i].first)
      right = max(right, eq[i++].second);
    // cout << left << " " << right << endl;
    for(int k = left ; k <= right ; k++){
      compOf[a[k]] = ncomp;
      comp[ncomp].push_back(a[k]);
    }
    ncomp++;
  }
  for(int i = 0 ; i < n ; i++)
    if(compOf[a[i]] == -1){
      compOf[a[i]] = ncomp;
      comp[ncomp++].push_back(a[i]);
    }
  if(ncomp < k)
    return printf("NO\n"), 0;
  int alp = 0;
  memset(ans, -1, sizeof ans);
  for(int i = 0 ; i < n ; i++){
    int cur = a[i];
    if(~ans[cur])
      continue;
    for(auto c : comp[compOf[cur]])
      ans[c] = alp;
    alp = min(25, alp + 1);
  }
  printf("YES\n");
  for(int i = 0 ; i < n ; i++)
    printf("%c", ans[i] + 'a');
  printf("\n");
  return 0;
}
