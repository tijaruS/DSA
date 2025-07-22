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

    int length = 0;
    ListNode *current = head;
    while (current) {
        length++;
        current = current->next;
    }
    k = k % length;
    if (k == 0)
        return head;

    for (int i = 0; i < k; i++) {

        ListNode *last = head;
        ListNode *prev = head;

        while (last->next) {
            last = last->next;
        }
        while (prev->next->next) {
            prev = prev->next;
        }
        last->next = head;
        prev->next = nullptr;
        head = last;
    }
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
