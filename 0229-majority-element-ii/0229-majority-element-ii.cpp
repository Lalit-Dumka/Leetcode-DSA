class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> sol;
        int n = nums.size();
        int el1 = INT_MIN, el2 = INT_MIN;
        int c1 = 0, c2 = 0;

        for(int i=0; i<n; i++){
            if(c1 == 0 && el2 != nums[i]){
                el1 = nums[i];
                c1=1;
            }
            else if(c2 == 0 && el1 != nums[i]){
                el2 = nums[i];
                c2=1;
            }
            else if(el1 == nums[i]){
                c1++;
            }
            else if(el2 == nums[i]){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }

        int a=0, b=0;
        for(int j=0; j<n; j++){
            if(nums[j]==el1){
                a++;
            }
            else if(nums[j]==el2){
                b++;
            }
        }

        if(a> (n/3.0)){
            sol.push_back(el1);
        }
        if(b> (n/3.0)){
            sol.push_back(el2);
        }

        
        return sol;
    }
};