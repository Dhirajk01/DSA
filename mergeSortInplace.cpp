#include <iostream>
#include <vector>
using namespace std;
void merge_inPlace(vector<int> &v, int start, int end, int mid)
{
    int total_len = end - start + 1;
    int gap = total_len / 2 + total_len % 2; // ceil
    while (gap > 0)
    {
        int i = start;
        int j = start + gap;
        while (j <= end)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
            ++i, ++j;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}
void mergeSort(vector<int> &v, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);

    merge_inPlace(v, start, end, mid);
}
int main()
{
    vector<int> v{3, 4, 2, 2,6, 7, 8, 0, 34, 23, 65};
    mergeSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}