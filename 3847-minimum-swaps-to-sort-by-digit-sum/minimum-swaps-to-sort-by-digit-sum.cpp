class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<vector<int>> v;
        int n =nums.size();
        for(int i=0; i<n; i++){
            int x=nums[i], sum=0;
            while(x >0){
                sum +=x%10;
                x =x/10;
            }
            v.push_back({sum ,nums[i], i});
        }
        sort(v.begin(), v.end());
        int swaps =0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(vis[i] || v[i][2]==i) continue;
            int j =i, len =-1;
            while(!vis[j]){
                vis[j] =true;
                j =v[j][2];
                len++;
            }
            swaps +=len;
        }
        return swaps;
    }
};