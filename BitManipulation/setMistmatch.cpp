#include <iostream>
#include <vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int xor_all = 0;
    int n = nums.size();
    
    // Compute the XOR of all numbers in nums and the numbers from 1 to n
    for (int num : nums) {
        xor_all ^= num;
    }
    for (int i = 1; i <= n; i++) {
        xor_all ^= i;
    }
    
    // Find the rightmost set bit in xor_all
    int rightmost_set_bit = xor_all & -xor_all;
    
    // Initialize two groups
    int xor_group1 = 0, xor_group2 = 0;
    
    // Partition the nums array based on the rightmost set bit
    for (int num : nums) {
        if (num & rightmost_set_bit) {
            xor_group1 ^= num;
        } else {
            xor_group2 ^= num;
        }
    }
    
    // Partition the range 1 to n based on the rightmost set bit
    for (int i = 1; i <= n; i++) {
        if (i & rightmost_set_bit) {
            xor_group1 ^= i;
        } else {
            xor_group2 ^= i;
        }
    }
    
    // Identify which of the two groups contains the duplicate number
    for (int num : nums) {
        if (num == xor_group1) {
            return {xor_group1, xor_group2}; // {duplicate, missing}
        }
    }
    return {xor_group2, xor_group1}; // {duplicate, missing}
}

int main() {
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = findErrorNums(nums);
    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}
