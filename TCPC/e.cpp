#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 1;
const int A = 26;

char s[N];
int cnt[A];

int main()
{
  scanf("%s", s);
  for(char* c = s; *c ; ++c)
    cnt[*c - 'a']++;
  for(int i = A - 1 ; i >= 0 ; i--)
    for(int j = 0 ; j < A ; j++)
      if(i != j && cnt[i]){
        cnt[i]--;
        cnt[j]++;
        int odd = 0;
        for(int c = 0 ; c < A ; c++)
          if(cnt[c] & 1)
            ++odd;
        if(odd == 1 || odd == 0){
          puts("Yes");
          for(int c = 0 ; c < A ; c++)
            for(int k = 0 ; k < cnt[c] / 2 ; k++)
              printf("%c", char('a' + c));
          for(int c = 0 ; c < A ; c++)
            if(cnt[c] & 1){
              printf("%c", char('a' + c));
              break;
            }
          for(int c = A - 1 ; c >= 0 ; c--)
            for(int k = 0 ; k < cnt[c] / 2 ; k++)
              printf("%c", char('a' + c));
          printf("\n");
          return 0;
        }
        cnt[i]++;
        cnt[j]--;
      }
  puts("No");
  return 0;
}
