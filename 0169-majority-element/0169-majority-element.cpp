class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algo
        int elem = nums[0], count =1;
        for (int i=1; i<nums.size(); i++){
            if(count==0){
                elem = nums[i];
                count=1;
            }
            else if(elem == nums[i]){
                count++;
            }
            else{
                count--;

            }
        }
        return elem;
        // int chk = 0;
        // for (int i=0; i<nums.size(); i++){
        //     if(nums[i]==elem){
        //         chk++;
        //     }
        // }
        // if(chk>(n/2)){
        //     return elem;
        // }
    }
};