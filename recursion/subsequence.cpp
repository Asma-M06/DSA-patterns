#include <iostream>
#include <vector>
using namespace std;

void subsequence(int ind, int arr[], vector<int> &seq, int n)
{
    if (ind == n)
    {
        for (auto it : seq)
        {
            cout << it << " ";
        }
        if (seq.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    seq.push_back(arr[ind]);
    subsequence(ind + 1, arr, seq, n);
    seq.pop_back();
    subsequence(ind + 1, arr, seq, n);
}

int main()
{
    cout<<"Enter number of elements: ";
    int n;
    cin >> n;
    int arr[n];
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> seq;
    subsequence(0, arr, seq, n);
}