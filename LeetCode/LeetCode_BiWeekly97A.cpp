class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int x:nums){
            vector<int> temp;
            while(x){
                temp.push_back(x%10);
                x/=10;
            }
            for(int i = temp.size()-1;i>=0;i--){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};