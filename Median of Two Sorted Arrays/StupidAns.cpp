class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        int beg1=0;
        int end1=len1;
        double ans;
        int i=(len1)/2;
        int j=(len1+len2-2*i)/2;
        if((len1+len2)%2==1)
        {
            if(len1==0) return nums2[len2/2];
            if(len2==0) return nums1[len1/2];
            do{
                if(i==0)
                {
                    if(nums2[j-1]>nums1[i]) {beg1=i;i=(i+end1+1)/2;}
                    else break;
                }
                else if(j==0)
                {
                    if(nums1[i-1]>nums2[j]) {end1=i;i=(i+beg1)/2;}
                    else break;
                }
                else if(j>len2){beg1=i;i=(i+end1+1)/2;}
                else if(j<0){end1=i;i=(i+beg1)/2;}
                else
                {
                    if(i==len1)
                    {
                        if(nums1[i-1]>nums2[j]) {end1=i;i=(i+beg1)/2;}
                        else break;
                    }
                    else if(j==len2)
                    {
                        if(nums2[j-1]>nums1[i]) {beg1=i;i=(i+end1+1)/2;}
                        else break;
                    }
                    else{
                        if(nums1[i-1]>nums2[j]) {end1=i;i=(i+beg1)/2;}
                        else if(nums2[j-1]>nums1[i]) {beg1=i;i=(i+end1+1)/2;}
                        else break;
                    }
                }
                j=(len1+len2-2*i)/2;
            } while(1);
            if(i+j>(len1+len2)/2.0)
            {
                if(i==0) ans=nums2[j-1];
                else if(j==0) ans=nums1[i-1];
                else ans=(nums1[i-1]>nums2[j-1])?nums1[i-1]:nums2[j-1];
            }
            else
            {
                if (i==len1) ans=nums2[j];
                else if(j==len2) ans=nums1[i];
                else ans=(nums1[i]<nums2[j])?nums1[i]:nums2[j];
            }
            return ans;
        }
        else
        {
            if(len1==0) return (nums2[len2/2]+nums2[len2/2-1])/2.0;
            if(len2==0) return (nums1[len1/2]+nums1[len1/2-1])/2.0;
            do{
                if(i==0)
                {
                    if(nums2[j-1]>nums1[i]) {beg1=i;i=(i+end1+1)/2;}
                    else break;
                }
                else if(j==0)
                {
                    if(nums1[i-1]>nums2[j]) {end1=i;i=(i+beg1)/2;}
                    else break;
                }
                else if(j>len2){beg1=i;i=(i+end1+1)/2;}
                else if(j<0){end1=i;i=(i+beg1)/2;}
                else
                {
                    if(i==len1)
                    {
                        if(nums1[i-1]>nums2[j]) {end1=i;i=(i+beg1)/2;}
                        else break;
                    }
                    else if(j==len2)
                    {
                        if(nums2[j-1]>nums1[i]) {beg1=i;i=(i+end1+1)/2;}
                        else break;
                    }
                    else{
                        if(nums1[i-1]>nums2[j]) {end1=i;i=(i+beg1)/2;}
                        else if(nums2[j-1]>nums1[i]) {beg1=i;i=(i+end1+1)/2;}
                        else break;
                    }
                }
                j=(len1+len2-2*i)/2;
            } while(1);
            int a1;
            double a2;
            if(i==0)a1=nums2[j-1];
            else if(j==0)a1=nums1[i-1];
            else a1=(nums1[i-1]>nums2[j-1])?nums1[i-1]:nums2[j-1];
            if(i==len1) a2=nums2[j];
            else if(j==len2)a2=nums1[i];
            else a2=(nums1[i]<nums2[j])?nums1[i]:nums2[j];
            return (a1+a2)/2;
        }
    }
};
