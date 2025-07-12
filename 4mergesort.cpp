#include <bits/stdc++.h>
using namespace std;

 void merge(int s,int e,vector<int> &nums)
   {
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first= new int[len1];
    int *second= new int[len2];
    int k=s;
    for(int i=0;i<len1;i++)
    { first[i]=nums[k++]; }
       for(int i=0;i<len2;i++)
    { second[i]=nums[k++]; }
    k=s;
    int i=0;
    int j=0;
    while(i<len1 && j<len2)
    {    if(first[i]<second[j])
       { nums[k++]=first[i++];}
       else{
        nums[k++]=second[j++];
       }
    }
    while(i<len1)
    {
        nums[k++]=first[i++];
    }
    while(j<len2)
    {
               nums[k++]=second[j++]; 
    }

   }
   void mergeSort(int s,int e,vector<int> &nums)
   {
    if(s>=e)
    {return;}
        int mid=s+(e-s)/2;
        mergeSort(s,mid,nums);
        mergeSort(mid+1,e,nums);
        merge(s,e,nums);


   }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
int main() {
    vector<int> arr={3,4,1,7};
	vector<int> sorted =sortArray(arr);
	for (int val : sorted) {
        cout << val << " ";
    }
    cout << endl;

    

}
