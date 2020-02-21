#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x) : val(x) {}
};

class Solution{
  int getSize(ListNode* head) {
    if(head == nullptr)
      return 0;
    return 1 + getSize(head->next);
  }
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int sz = getSize(head);
    if(n > sz)
      return head;
    n = sz - n;
    if(n == 0){
      head = head->next;
      return head;
    }
    ListNode* a = head;
    for(int it = 0 ; it < n - 1 ; it++) {
      a = a->next;
    }
    a->next = a->next->next;
    return head;
  }
};

int main()
{
  
  return 0;
}
