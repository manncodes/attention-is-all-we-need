/*
 * Given an Array of integers representing an elevation map where width of each bar is 1,
 * return how much rainwater can be trapped.
 */
/// Brute Force
var heights = [0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2];
/*
 *   3|                  __
 *   2|         __      |  |         __
 *   1|   __   |  |## ##|  |## ## ##|  |
 *   0|__|__|##|__|__|##|__|__|##|__|__|
 *     0  1  0  2  1  0  3  1  0  1  2
 */
var getTrappedRainwater = function (heights) {
    var totalWater = 0;
    for (var p = 0; p < heights.length; p++) {
        var leftP = p;
        var rightP = p;
        var maxLeft = 0;
        var maxRight = 0;
        while (leftP >= 0) {
            maxLeft = Math.max(maxLeft, heights[leftP]);
            leftP--;
        }
        while (rightP < heights.length) {
            maxRight = Math.max(maxRight, heights[rightP]);
            rightP++;
        }
        var currentWater = Math.min(maxLeft, maxRight) - heights[p];
        if (currentWater >= 0)
            totalWater += currentWater;
    }
    return totalWater;
};
var getTrappedRainwaterOpt = function (heights) {
    var totalWater = 0, left = 0, right = heights.length - 1, maxLeft = 0, maxRight = 0;
    while (left < right) {
        if (heights[left] <= heights[right]) {
            if (heights[left] >= maxLeft)
                maxLeft = heights[left];
            else
                totalWater += maxLeft - heights[left];
            left++;
        }
        else {
            if (heights[right] >= maxRight)
                maxRight = heights[right];
            else
                totalWater += maxRight - heights[right];
            right--;
        }
    }
    return totalWater;
};
console.time('rainwater');
console.log(getTrappedRainwater(heights));
console.timeEnd('rainwater');
console.time('rainwaterOpt');
console.log(getTrappedRainwaterOpt(heights));
console.timeEnd('rainwaterOpt');
