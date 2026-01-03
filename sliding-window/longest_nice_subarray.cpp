/*
Approach : sliding window
variables:l,r,best,distinct
data structure: vector/array


steps:
1.Take user inputted array/vector
2.initialize l=0,distinct=0,best=0
3.loop r through vector/array:
    store freq of elements
    if freq of element == 1
        distinct++;
    while(distinct>2):
        reduce freq of element
        if freq ==0 => distinct --
        shrink window from left
    set best as max of best and window size
return best



testcases:
nums = [1,2,1]
Output = 3

nums = [0,1,2,2]
Output = 3

nums = [1,2,3,2,2]
Output = 4


*/
// code:

#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
int longestNiceSubarray(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int left = 0;
    int best = 0;
    int distinct = 0;
    for (int r = 0; r < nums.size(); r++)
    {
        freq[nums[r]]++;
        if (freq[nums[r]] == 1)
        {
            distinct++;
        }

        while (distinct > 2)
        {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
            {
                distinct--;
            }
            left++;
        }
        best = max(best, r - left + 1);
    }
    return best;
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = longestNiceSubarray(nums);
    cout << result;

    return 0;
}