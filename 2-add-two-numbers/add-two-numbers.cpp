// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         vector<ListNode*> v1,v2;
//         ListNode *curr =l1;
//         while(curr){
//             v1.push_back(curr);
//             curr =curr->next;
//         }
//         curr =l2;
//         while(curr){
//             v2.push_back(curr);
//             curr =curr->next;
//         }
//         int p =v1.size(), q=v2.size(), i=0, z=0;
//         vector<ListNode*> v;
//         while(i <p && i< q){

//             int a =v1[i]->val;
//             int b =v2[i]->val;
            
//             int x= a+b+z;
//             int y =x% 10;
//             z =x/10;

//             v.push_back(new ListNode(y));
//             i++;
//         }
        
//         // Remaining elements of v1
//         while (i < p) {
//             int x = v1[i]->val + z;
//             int y = x % 10;

//             z = x / 10;

//             v.push_back(new ListNode(y));
//             i++;
//         }
//         // Remaining elements of v2
//         while (i < q) {
//             int x = v2[i]->val + z;
//             int y = x % 10;

//             z = x / 10;

//             v.push_back(new ListNode(y));
//             i++;
//         }

//         // Remaining carry
//         if (z) {
//             v.push_back(new ListNode(z));
//         }

//         ListNode *ans =new ListNode();
//         ListNode *temp =ans;
//         for(auto ele :v){
//             temp->next =ele;
//             temp =temp->next;
//         }
//         temp->next =nullptr;
//         return ans->next;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        
        return dummy->next;
    }
};