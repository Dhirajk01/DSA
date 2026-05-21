#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;
int numPerfectSquare(int n){
     // base case
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);

        while (i <= end) {
            int perfectSquare = i * i;
            int noOfPerfectSquare = 1 + numPerfectSquare(n - perfectSquare);
            if (noOfPerfectSquare < ans) {
                ans = noOfPerfectSquare;
            }
            i++;
        }
        return ans;
    }

int main()
{

    int n = 12;
int ans=numPerfectSquare(n);
    cout << "Minimum perfect squares needed for "
         << n << " is : "
         << ans-1 << endl;

    return 0;
}