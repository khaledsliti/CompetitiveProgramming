#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
char s[N];
int arr[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d%s", &n, s);
    int cur = n;
    for(int i = 0 ; i < n ; i++){
      arr[i] = 0;
    }
    for(int i = 0 ; i < n - 1 ; i++){
      if(s[i] == '>'){
        arr[i] = cur--;
      }
    }
    for(int i = 0 ; i < n ; i++){
      if(arr[i] == 0){
        int j = i;
        while(j < n && arr[j] == 0)
          j++;
        j--;
        while(j >= i)
          arr[j--] = cur--;
      }
    }
    for(int i = 0 ; i < n ; i++)
      printf("%d ", arr[i]);
    printf("\n");
    cur = n;
    for(int i = 0 ; i < n ; i++){
      arr[i] = 0;
    }
    for(int i = n - 2 ; i >= 0 ; i--){
      if(s[i] == '<')
        arr[i + 1] = cur--;
    }
    for(int i = n - 1 ; i >= 0 ; i--){
      if(arr[i] == 0){
        int j = i;
        while(j >= 0 && arr[j] == 0) j--;
        j++;
        while(j <= i)
          arr[j++] = cur--;
      }
    }
    for(int i = 0 ; i < n ; i++)
      printf("%d ", arr[i]);
    printf("\n");
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity