#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int arr[N];

int main()
{
  scanf("%d", &n);
  long long sum = 0;
  for(int i = 0 ; i < n ; i++){
    scanf("%d", arr + i);
    sum += arr[i];
  }
  sort(arr, arr + n);
  if((sum & 1) != 0 || (sum - arr[n - 1] < arr[n - 1]))
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
