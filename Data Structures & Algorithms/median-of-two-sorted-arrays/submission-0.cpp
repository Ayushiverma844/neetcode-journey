class Solution {
public:
     // Function to merge two sorted arrays into one sorted array
     vector<double> merge(vector<int>& nums1, vector<int>& nums2){
        int i=0 , j=0;
        vector<double> sorted(nums1.size()+nums2.size());
        int k=0;

        // Merge two sorted arrays while maintaining sorted order
        while(i< nums1.size() && j <nums2.size()){
             if(nums1[i] <= nums2[j]){
                sorted[k] = nums1[i];
                i++;
                k++;
             }
             else{
                sorted[k] = nums2[j];
                j++;
                k++;
             }
        }
         // Copy remaining elements from nums1 (if any)
         while(i < nums1.size()){
            sorted[k] = nums1[i];
            i++;
            k++;
         }
          // Copy remaining elements from nums2 (if any)
         while(j < nums2.size()){
             sorted[k] = nums2[j];
                j++;
                k++;
         }
      return sorted;
     }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         // Merge both arrays
        vector<double> combine = merge(nums1,nums2);
        int n = combine.size();

        // Case 1: If total number of elements is odd
        if(n%2 != 0){
            return combine[n/2] ;  //middle element
        }
        // Case 2: If even, take average of two middle elements
        else{
            return (combine[n/2] + combine[n/2 - 1]) / 2.0;
        }

    }
};
