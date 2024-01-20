// reverseListLimit.cpp : Nithin
// desc : a program to reverse a linked list within a given range

#include <iostream>

template <typename T>
struct ListNode
{
    T value;
    ListNode *next;

    ListNode(const T &v) : value(v), next(nullptr) {}
};

ListNode<int> *ReverseListInKGroups(ListNode<int> *l, int k)
{
    if (l == nullptr)
        return nullptr;

    int numNodes = 0;
    ListNode<int> *curr = l;

    while (curr != nullptr && numNodes < k)
    {
        curr = curr->next;
        numNodes++;
    }

    if (numNodes < k)
        return l;

    int nodes = 0;
    ListNode<int> *prev = nullptr, *next = nullptr;
    curr = l;
    while (nodes < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        nodes++;
    }
    l->next = ReverseListInKGroups(next, k);

    return prev;
}

void PrintList(ListNode<int> *head)
{
    ListNode<int> *c = head;

    while (c != nullptr)
    {
        std::cout << c->value << " ";
        c = c->next;
    }

    return;
}

int main()
{
    ListNode<int> *head = new ListNode<int>(1);
    head->next = new ListNode<int>(2);
    head->next->next = new ListNode<int>(3);
    head->next->next->next = new ListNode<int>(4);
    head->next->next->next->next = new ListNode<int>(5);
    head->next->next->next->next->next = new ListNode<int>(6);
    head->next->next->next->next->next->next = new ListNode<int>(7);

    PrintList(head);

    // use reverse in k groups
    int k = 3;

    ListNode<int> *newHead = ReverseListInKGroups(head, k);

    std::cout << std::endl;

    PrintList(newHead);

    return 0;
}