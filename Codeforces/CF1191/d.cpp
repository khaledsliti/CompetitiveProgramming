#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
 
int n;
int arr[N];
 
int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  sort(arr, arr + n);
  int cnt = 0, At;
  for(int i = 0 ; i + 1 < n ; i++){
    if(arr[i] == arr[i + 1]){
      if(!arr[i]){
        cout << "cslnb" << endl;
        return 0;
      }
      cnt++;
      At = i;
    }
  }
  if(cnt > 1 || (cnt == 1 && (At > 0 && arr[At - 1] + 1 == arr[At]))){
    cout << "cslnb" << endl;
    return 0;
  }
  long long sum = arr[0];
  arr[0] = 0;
  for(int i = 1 ; i < n ; i++){
    int x = arr[i];
    if(x == arr[i - 1])
      continue;
    sum += x - arr[i - 1] - 1;
    arr[i] = arr[i - 1] + 1;
  }
  if(sum & 1)
    cout << "sjfnb" << endl;
  else
    cout << "cslnb" << endl;
  return 0;
}