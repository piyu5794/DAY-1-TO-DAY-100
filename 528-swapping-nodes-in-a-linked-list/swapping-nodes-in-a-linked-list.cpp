class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *x =new ListNode();

        vector< ListNode*> v;
        ListNode *temp =head, *t= x;
        while(temp){
            v.push_back(temp);
            temp =temp->next;
        }        
        int n =v.size();
        for(int i=0 ;i<n; i++){
            if(i ==k-1) t->next =v[n-k];
            else if(i ==n-k) t->next =v[k-1];
            else t->next =v[i];
            t =t->next;
        }
        t->next =nullptr;
        return x->next;
    }
};