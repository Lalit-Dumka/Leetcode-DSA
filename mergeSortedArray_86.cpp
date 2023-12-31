class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(n>0){
            if( m && nums1[m-1]>=nums2[n-1]){
                nums1[m+n]=nums1[--m];
            }
            else{
                nums1[m+n]=nums2[--n];
            }
        }
    }
};