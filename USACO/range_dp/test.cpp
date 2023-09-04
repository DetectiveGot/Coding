#include <iostream>
#include <vector>


using namespace std;

int minMovesToMakeIncreasing(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 0);

    for (int i = 1; i < n; ++i) {
        dp[i] = std::max(0, dp[i - 1] + nums[i - 1] - nums[i]);
        nums[i] = std::max(nums[i], nums[i - 1] + 1);
    }

    int totalMoves = 0;
    for (int i = 0; i < n; ++i) {
        totalMoves += dp[i];
    }

    return totalMoves;
}

int main() {
	int n; cin >> n;
    vector<int> nums(n);
    for(auto&e:nums) cin >> e;
    int moves = minMovesToMakeIncreasing(nums);
    std::cout << "Minimum moves to make the array increasing: " << moves << std::endl;
    return 0;
}

