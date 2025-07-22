#include <bits/stdc++.h>
struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *solve(int n, int k, ListNode *head) {
  if (!head || k == 1)
    return head;
  ListNode *dummy = new ListNode(0);
  dummy->next = head;

  int cnt = 0;

  ListNode *cur = dummy, *pre = dummy, *nex = dummy;
  while (cur->next) {
    cnt++;
    cur = cur->next;
  }

  while (cnt >= k) {
    cur = pre->next;
    nex = cur->next;

    for (int i = 1; i < k; i++) {
      cur->next = nex->next;
      nex->next = pre->next;
      pre->next = nex;
      nex = cur->next;
    }
    cnt -= k;
    pre = cur;
  }
  return dummy->next;
}
int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> n >> k;
    ListNode *head = nullptr;
    ListNode *current = nullptr;
    if (n > 0) {
      int firstElement;
      std::cin >> firstElement;
      head = new ListNode(firstElement);
      current = head;
    }
    for (int i = 1; i < n; i++) {
      int a;
      std::cin >> a;
      ListNode *temp = new ListNode(a);
      current->next = temp;
      current = temp;
    }
    ListNode *node = solve(n, k, head);
    while (node) {
      std::cout << node->val << ' ';
      node = node->next;
    }
    std::cout << std::endl;
  }
  return 0;
}
