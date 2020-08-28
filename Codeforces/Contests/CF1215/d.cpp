#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
char s[N];

void solve(int steps, int sum)
{
  // cout << steps << " " << sum << endl;
  if(sum <= 0){
    cout << "Monocarp" << endl;
    return;
  }
  int f = steps / 2;
  if(f * 9 > sum){
    cout << "Monocarp" << endl;
    return;
  }
  if(f * 9 < sum){
    cout << "Monocarp" << endl;
    return;
  }
  cout << "Bicarp" << endl;
}

int main()
{
  scanf("%d", &n);
  scanf("%s", s);
  int sum_left = 0, sum_right = 0;
  int left = 0, right = 0;
  for(int i = 0 ; i < n / 2 ; i ++){
    if(s[i] == '?')
      left++;
    else
      sum_left += s[i] - '0';
  }
  for(int i = n / 2 ; i < n ; i++){
    if(s[i] == '?')
      right++;
    else
      sum_right += s[i] - '0';
  }
  // cout << right << " " << left << endl;
  if(left < right){
    solve(right - left, sum_left - sum_right);
  }else if(right < left){
    solve(left - right, sum_right - sum_left);
  }else{
    if(sum_left == sum_right)
      cout << "Bicarp" << endl;
    else
      cout << "Monocarp" << endl;
  }
  return 0;
}
