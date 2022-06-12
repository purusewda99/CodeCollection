/*A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.*/
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    if(nums.size() == 1)    return 0;

    int n = nums.size();

    //check if 0th/(n-1)th index is the peak element
    if(nums[0] > nums[1])   return 0;
    if(nums[n-1] > nums[n-2])   return (n-1);

    int start = 1, end = n-2;

    while(start <= end) {
        int mid = start+(end-start)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            return mid;
        else if(nums[mid] < nums[mid-1])    
            end = mid-1;
        else if(nums[mid] < nums[mid+1])
            start = mid+1;
    }
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> nums;
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    int out = findPeakElement(nums);
    cout << out;
    return 0;
}