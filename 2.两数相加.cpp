// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem2.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool s1, s2;
        int num1, num2, num_sum, num_now, num_next;
        ListNode *root = new ListNode(0);
        ListNode *lt = root;
        num_next = 0;
        while (l1 != NULL || l2 != NULL || num_next == 1)
        {
            s1 = l1 == NULL;
            s2 = l2 == NULL;
            num1 = s1 ? 0 : l1->val;
            num2 = s2 ? 0 : l2->val;
            num_sum = num1 + num2 + num_next;
            ListNode *tmp = new ListNode(num_sum % 10);
            lt->next = tmp;
            lt = lt->next;
            num_next = num_sum / 10;
            l1 = s1 ? l1 : l1->next;
            l2 = s2 ? l2 : l2->next;
        }
        return root->next;
    }
};
// @lc code=end
