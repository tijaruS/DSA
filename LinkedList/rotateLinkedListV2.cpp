#include <bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *solve(int n, int k, ListNode *head) {
    if (!head || !head->next || k == 0)
        return head;

    int length = 1;
    ListNode *last = head;
    while (last->next) {
        length++;
        last = last->next;
    }

    last->next = head;
    k = k % length;
    k = length - k;
    ListNode *temp = head;
    while (--k) {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;

    return head;
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
            int firstList;
            std::cin >> firstList;
            head = new ListNode(firstList);
            current = head;
        }
        for (int i = 1; i < n; i++) {
            int element;
            std::cin >> element;
            ListNode *temp = new ListNode(element);

            current->next = temp;
            current = temp;
        }
        ListNode *ans = solve(n, k, head);

        while (ans) {
            std::cout << ans->val;
            if (ans->next)
                std::cout << "-->";
            ans = ans->next;
        }
        std::cout << "--> nullptr" << std::endl;
        ListNode *tempDel = head;
        while (tempDel) {
            ListNode *nextNode = tempDel->next;
            delete tempDel;
            tempDel = nextNode;
        }
    }

    return 0;
}
