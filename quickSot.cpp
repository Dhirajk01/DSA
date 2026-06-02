#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &v, int start, int end)
{
    int idx = start - 1;
    int pivotElement = v[end];

    for (int i = start; i < end; i++)
    {
        if (v[i] <= pivotElement)
        {
            idx++;
            swap(v[i], v[idx]);
        }
    }
    idx++;
    swap(v[idx], v[end]);

    return idx;
}

void quickSort(vector<int> &v, int start, int end)
{
    // base case
    if (start >= end)
        return;

    // partition
    int p = partition(v, start, end);
    // left
    quickSort(v, start, p - 1);
    // right
    quickSort(v, p + 1, end);
}
int main()
{
    vector<int> v{100, 4, 6, 78, 90};
    quickSort(v, 0, v.size() - 1);

    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}
