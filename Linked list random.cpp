/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int len=0;
    ListNode*headNode;
    
    Solution(ListNode* head) {
        headNode=head;
        ListNode*tmp=headNode;
        while(tmp){
            len++;
            tmp=tmp->next;
        }
    }
    
    int getRandom() {
        int rand_index=rand()%len;
        ListNode*tmp=headNode;
        for(int i=0;i<rand_index;i++){
            tmp=tmp->next;
        }
        return tmp->val;
    }   
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */