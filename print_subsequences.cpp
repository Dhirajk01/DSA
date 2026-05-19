#include <iostream>
#include <vector>
using namespace std;

void printSubsequence(string s, string output, int i, vector<string> &v)
{

    // base case
    if (i >= s.length())
    {
        v.push_back(output);
        return;
    }

    // exclude
    printSubsequence(s, output, i + 1, v);

    // include
    output.push_back(s[i]);
    printSubsequence(s, output, i + 1, v);
}

int main()
{
    string s = "abc";
    string output = "";
    int i = 0;
    vector<string> v;
    printSubsequence(s, output, i, v);

    for (auto i : v)
    {
        cout << i << endl;
    }
    cout<< v.size();
}