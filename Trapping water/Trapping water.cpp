#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0;
    }

    vector<int> left(n), right(n);
    left[0] = 0;
    int lMax = height[0];
    for (int i = 0; i < n; i++) {
        left[i] = lMax;
        lMax = max(lMax, height[i]);
    }

    right[n - 1] = 0;
    int rMax = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = rMax;
        rMax = max(rMax, height[i]);
    }

    int water = 0;
    for (int i = 1; i < n - 1; i++) {
        if (height[i] < left[i] && height[i] < right[i]) {
            water += min(left[i], right[i]) - height[i];
        }
    }
    return water;
}

int main()
{
    vector<int> a = { 5,3,1,3,1,4,1,7,4,3,2,1,0,2,5,7 };
    cout << trap(a);
}