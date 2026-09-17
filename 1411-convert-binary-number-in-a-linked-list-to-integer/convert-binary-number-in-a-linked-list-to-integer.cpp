class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        ListNode *curr =head;
        while(curr){
            v.push_back(curr->val);
            curr =curr->next;
        }
        int ans =0, n=v.size() ,j=0;
        for(int i=0; i<n; i++){
            ans = ans*2 + v[i];
            j++;
        }
        return ans;
    }
};