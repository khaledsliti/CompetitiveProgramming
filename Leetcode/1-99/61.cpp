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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL) return head;
    int length = 0;
    for(ListNode* cur = head; cur != NULL; cur = cur->next)
      length++;
    k = k % length;
    if(k == 0) return head;
    ListNode* tail = head;
    for(int rem = length - 1 ; rem > k ; rem--)
      tail = tail->next;
    ListNode* newHead = tail->next;
    tail->next = NULL;
    ListNode* cur = newHead;
    for(; cur->next != NULL ; cur = cur->next);
    cur->next = head;
    return newHead;
  }
};

int main()
{
  
  return 0;
}
