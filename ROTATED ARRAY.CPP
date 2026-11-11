class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // if (n == 0) return -1;

        int i = 0, j = n - 1;

        // Find pivot
        while (i < j) {
            int mid = i + (j - i) / 2;

            if (nums[mid] > nums[j])
                i = mid + 1;
            else
                j = mid;
        }

        int pivot = i;

        // Select the correct sorted half
        if (target >= nums[pivot] &&
            target <= nums[n - 1]) {
            i = pivot;
            j = n - 1;
        } else {
            i = 0;
            j = pivot - 1;
        }

        // Binary search
        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }

        return -1;
    }
};
