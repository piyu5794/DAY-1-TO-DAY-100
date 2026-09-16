class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp =list2, *curr =list1;
        while(temp->next){
            temp =temp->next;
        }
        int i =1;
        while(curr){
            if(i ==a){
                ListNode *prev =curr->next;
                curr->next =list2;
                curr =prev;
            }
            curr =curr->next;
            if(i==b) break;
            i++;
        }
        temp->next =curr;
        return list1;
    }
};