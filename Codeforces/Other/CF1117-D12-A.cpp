/********************************************************************************************************
  Author: RedStone

  Problem link:
  	https://codeforces.com/contest/1117/problem/A

  Idea:
  	In this problem, we just need to find the length of the longest sub-array containing the maximum element.

  Compexity:
  	Time: O(N)
  	Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
typedef long long ll;

const int N = 1e5 + 5;

int n, arr[N];

int main()
{
  cin >> n;
  int mx = 0;
  for(int i = 0 ; i < n; i++){
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }
  int len = 0;
  for(int i = 0 ; i < n ; i++){
    if(arr[i] != mx)
      continue;
    int j = i;
    while(j < n && arr[i] == arr[j])
      ++j;
    len = max(len, j - i);
    i = j - 1;
  }
  cout << len << endl;
  return 0;
}
