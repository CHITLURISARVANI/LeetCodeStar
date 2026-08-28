class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int s = n/2;
        map<int, int> count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;;
            if(count[nums[i]] > s){
                return nums[i];
            }
        }
        return -1;
    }
};