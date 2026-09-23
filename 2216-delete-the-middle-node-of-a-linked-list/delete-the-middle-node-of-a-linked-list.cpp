class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *curr =head;
        if (!head || !head->next) return nullptr;
        int count =0;
        while(curr){
            curr =curr->next;
            count++;
        }
        curr =head;
        int k =1;
        while(curr){
            if(k== count/2){
                curr->next =curr->next->next;
            }
            else curr =curr->next;
            k++;
        }
        return head;
    }
};