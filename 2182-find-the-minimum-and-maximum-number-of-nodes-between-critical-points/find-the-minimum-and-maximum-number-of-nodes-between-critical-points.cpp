class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};
        ListNode *a=head;
        ListNode *b= head->next;
        ListNode *c =head->next->next;
        
        int idx=1,firstIdx =-1,lastIdx= -1;
        int f=-1, s=-1;
        int mn= INT_MAX;
        while(c){
            if(b->val > a->val &&b->val>c->val || b->val< a->val &&b->val<c->val ){
                if(firstIdx==-1) firstIdx =idx;
                lastIdx =idx;
                f=s;
                s=idx;
                if(f!=-1){
                    int d= s-f;
                    mn =min(mn,d);
                }
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
        if(mn==INT_MAX) return {-1,-1};
        int mx= lastIdx -firstIdx;
        return {mn,mx};
    }
};