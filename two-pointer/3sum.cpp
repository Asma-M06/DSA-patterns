/*
Approach : 2-pointer + fixed variable logic
variables: left , right , i , sum
data structure: array/vector

steps:
1.take user inputted array size and elements
2.Sort the array for ease of duplicates
4.initialize result
3.Fix i as 0
let target = - nums[i]
for other 2 pairs perform 2sum:
        --left = i+1, right = n-1
        --while(left < right)
            -- sum = array[left]+array[right]
            -- if sum == target:
                --- push i,left,right to result
                --- left++ right--
            else if sum > target : right--
            else : left++
return result
testcases:
[-1,0,1,2,-1,-4]  ->  [[-1,-1,2], [-1,0,1]]
[0,0,0]  -> [[0,0,0]]
[1,2,-2,-1]  -> []
*/

// code:
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> &arr, int n)
{
    vector<vector<int> > result;

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1, right = n - 1;
        int target = -arr[i];
        while (left < right)
        {
            int sum = arr[left] + arr[right];
            if (sum == target)
            {
                result.push_back(vector<int>{arr[i], arr[left], arr[right]});
                left++;
                right--;

                while (left < right && arr[left] == arr[left - 1])
                    left++;
                while (left < right && arr[right] == arr[right + 1])
                    right--;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    vector<vector<int> > result = threeSum(arr, n);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "]";
    }

    return 0;
}


