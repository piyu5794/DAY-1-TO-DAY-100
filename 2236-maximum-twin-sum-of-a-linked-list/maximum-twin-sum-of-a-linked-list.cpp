// class Solution {
// public:
//     int size(ListNode *head){
//         if(head== NULL) return 0;
//         return 1 +size(head->next);  
//     }
//     int pairSum(ListNode* head) {
//         int n =size(head);
//         ListNode *curr =head, *tail =head;
//         while(tail->next){
//             tail =tail->next;
//         }
//         int sum =0, ans =0;
//         for(int i=0; i< n/2; i++){
//             sum =curr->val +tail->val;
//             ListNode *prev =curr;
//             curr =curr->next;
//             while(prev->next !=tail){
//                 prev =prev->next;
//             }
//             tail =prev;
//             ans =max(sum ,ans);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow= head, *fast =head;
        while(fast && fast->next){
            slow =slow->next;
            fast =fast->next->next;
        } 
        ListNode *prev =NULL ,*curr =slow;
        while(curr){
            ListNode *nxt =curr->next;
            curr->next =prev;
            prev =curr;
            curr =nxt;
        }
        int sum =0, ans=0;
        ListNode *first =head, *sec =prev;
        while(sec){
            sum =first->val +sec->val;
            ans =max(sum ,ans);
            first =first->next;
            sec =sec->next;
        }
        return ans;
    }
};