#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
      return head;
    ListNode* h = swapPairs(head->next->next);
    ListNode* nh = head->next;
    nh->next = head;
    head->next = h;
    return nh;
  }
};

int main()
{
  
  return 0;
}
