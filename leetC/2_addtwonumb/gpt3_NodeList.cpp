#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* prev = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (prev == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }

    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> values = {1, 2, 3};
    ListNode* head = createLinkedList(values);

    printLinkedList(head);

    // Clean up the memory (deallocating the dynamically allocated nodes)
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
