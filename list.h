#ifndef LIST_H
#define LIST_H

#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

//为了编程服务，这里不需要泛型，不是所有的地方都需要泛型
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) { }
};

void showList(ListNode *head) {
    assert(head != nullptr);
    while (head->next != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;
    return;
}

ListNode *reverseListInPlace(ListNode *head) {
    assert(head != nullptr);
    ListNode l(head->val);
    while (head) {
        ListNode *pre = head->next; 
        head->next = l.next;
        l.next = head;
        head = pre;
    }
    return l.next;
}

ListNode *constructList(vector<int> &nums)
{
    assert(nums.size() != 0);
    ListNode l(nums[0]);
    ListNode *cur = &l;
    for (int i = 0; i < nums.size(); i++)
    {
        ListNode *pre = new ListNode(nums[i]);
        cur->next = pre;
        cur = cur->next;
    }
    return l.next;
}

//list 模板
/*
template <class elementType>
struct ListNode
{
    elementType val;
    ListNode *next;
    ListNode(elementType x) : val(x), next(nullptr){};
};

template <class elementType>
void showList(ListNode<elementType> *head) {
    assert(head != nullptr);
    while (head->next != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;
    return;
}

template <class elementType>
ListNode<elementType> *reverseListInPlace(ListNode<elementType> *head) {
    assert(head != nullptr);
    ListNode<elementType> l(head->val);
    // l.next = head;
    while (head) {
        ListNode<elementType> *pre = head->next; 
        head->next = l.next;
        l.next = head;
        head = pre;
    }
    return l.next;
}

template <class elementType>
ListNode<elementType> *constructList(vector<elementType> &nums)
{
    assert(nums.size() != 0);
    ListNode<elementType> l(nums[0]);
    ListNode<elementType> *cur = &l;
    for (int i = 0; i < nums.size(); i++)
    {
        ListNode<elementType> *pre = new ListNode<elementType>(nums[i]);
        cur->next = pre;
        cur = cur->next;
    }
    return l.next;
}
*/
#endif