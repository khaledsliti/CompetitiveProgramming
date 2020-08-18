#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int arr[N];
int sol[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    bool good = true;
    set<int> values;
    for(int i = 0 ; i < n ; i++)
      scanf("%d", arr + i), values.insert(i + 1);
    sol[0] = arr[0];
    values.erase(arr[0]);
    for(int i = 1 ; i < n ; i++){
      if(arr[i] < i + 1)
        good = false;
      sol[i] = arr[i - 1] != arr[i] ? arr[i] : -1;
      if(sol[i] != -1)
        values.erase(sol[i]);
    }
    if(!good){
      puts("-1");
      continue;
    }
    for(int i = 0 ; i < n ; i++)
      if(sol[i] == -1){
        sol[i] = *values.begin();
        values.erase(sol[i]);
      }
    for(int i = 0 ; i < n ; i++)
      printf("%d ", sol[i]);
    puts("");
  }
  return 0;
}
