class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> pos;
        sort(banned.begin(),banned.end());
        for(int i = 1;i <= n;i++){
            if(!(binary_search(banned.begin(),banned.end(),i))){
                pos.push_back(i);
            }
        }
        int po = 0, sum = 0;
        for(int x:pos){
            if((long long)(sum + x) <= maxSum){
                po++;
                sum += x;
            }
            else{
                break;
            }
        }
        return po;
    }
};