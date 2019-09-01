#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int arr[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  int best = 0;
  for(int i = 0 ; i < n ; i++){
    int j = i + 1;
    while(j < n && arr[j] <= arr[j - 1])
      ++j;
    best = max(best, j - i - 1);
    i = j - 1;
  }
  cout << best << endl;
  return 0;
}
