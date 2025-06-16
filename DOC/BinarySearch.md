# Binary Search

左侧边界/右侧边界问题


## 寻找左侧边界的二分搜索

```cpp
int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            right = mid - 1;
        }
    }
    return left;
}
```

## 寻找右侧边界的二分搜索

```cpp
int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 这里改成收缩左侧边界即可
            left = mid + 1;
        }
    }
    // 最后改成返回 left - 1
    if (left - 1 < 0 || left - 1 >= nums.size()) {
        return -1;
    }
    return nums[left - 1] == target ? (left - 1) : -1;
}
```
