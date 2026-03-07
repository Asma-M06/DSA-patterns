#include <iostream>
#include <vector>
using namespace std;

void subsequence_sum_k(int ind, int arr[], int n, vector<int> &seq, int sum, int s)
{
    if (ind == n)
    {
        if (sum == s)
        {
            cout<<"[ ";
            for (auto it : seq)
            {
                cout << it << " ";
            }
            cout<<"]";
            cout<<endl;
        }
        return;
    }

    seq.push_back(arr[ind]);
    sum += arr[ind];
    subsequence_sum_k(ind + 1, arr, n, seq, sum, s);
    seq.pop_back();
    sum -= arr[ind];
    subsequence_sum_k(ind + 1, arr, n, seq, sum, s);
}

int main()
{
    int s;
    int n;
    int arr[100];
    vector<int> seq;
    cout << "Enter the number of elements and sum value: ";
    cin >> n >> s;
    cout << "Enter the element :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    subsequence_sum_k(0, arr, n, seq, 0, s);

    return 0;
}


// what if asked to print only one subsequence with sum k then we can return true when we find the first subsequence with sum k and return false if we reach the end of the array without finding any subsequence with sum k.

/*
lets modify the above code to print only one subsequence with sum k

bool subsequence_sum_k(int ind, int arr[], int n, vector<int> &seq, int sum, int s)
{
    if (ind == n)
    {
        if (sum == s)
        {
            cout<<"[ ";
            for (auto it : seq)
            {
                cout << it << " ";
            }
            cout<<"]";
            cout<<endl;
            return true;
        }
        return false;
    }

    seq.push_back(arr[ind]);
    sum += arr[ind];
    if (subsequence_sum_k(ind + 1, arr, n, seq, sum, s)) {
        return true;
    }
    seq.pop_back();
    sum -= arr[ind];
    if (subsequence_sum_k(ind + 1, arr, n, seq, sum, s)) {
        return true;
    }
    return false;
}

so we see the function is bool type that returns true if we find a subsequence with sum k and false if we don't find any subsequence with sum k. we check for the first subsequence by including the current element and if we find a subsequence with sum k then we return true otherwise we backtrack and check for the second subsequence by excluding the current element and if we find a subsequence with sum k then we return true otherwise we return false.


so template to keep in mind is 

function(){
    base case ()---->satisfied
          return true
    else false
    
    recursive case ()---->satisfied
          return true
    else false
    
    }
*/