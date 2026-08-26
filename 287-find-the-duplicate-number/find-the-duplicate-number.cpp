class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int n = nums.size();
        map<int, int> count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
            if(count[nums[i]] >= 2){
                return nums[i];
            }
        }
        return -1;
    }
};