class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector< ListNode* >v;
        ListNode *curr =head;
        while(curr){
            v.push_back(curr);
            curr =curr->next;
        }
        sort(v.begin(), v.end(),[](ListNode *a,ListNode *b){
            return a->val <b->val;
        });
        ListNode *ans =new ListNode();
        ListNode *temp =ans;
        for(auto ele :v){
            temp->next =ele;
            temp =temp->next;
        }
        temp->next =nullptr;
        return ans->next;
    }
};