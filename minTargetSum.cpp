#include <iostream>
#include<vector>
#include <limits.h>
using namespace std;
int solve(vector<int> &arr, int target)
{
    if (target == 0)
        return 0;

    if (target < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solve(arr, target - arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}
int main()
{
    int target = 20;
    vector<int> arr{1, 2, 3};
    int result = solve(arr, target);
    cout << "Required number of elements is = " << result;
}