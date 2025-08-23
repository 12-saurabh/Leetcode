
class Solution {
public:

    int minArea(vector<vector<int>>& grid, int starti, int endi, int startj, int endj) {
        int n = grid.size();
        int m = grid[0].size();

        if (starti > endi || startj > endj) return 0;
        if (starti < 0 || endi >= n || startj < 0 || endj >= m) return 0;

        int i, j, startrow = 1e9, endrow = -1, startcol = 1e9, endcol = -1, found = 0;

        for (i = starti; i <= endi; i++) {
            for (j = startj; j <= endj; j++) {
                if (grid[i][j]) {
                    startrow = min(startrow, i);
                    endrow = max(endrow, i);
                    startcol = min(startcol, j);
                    endcol = max(endcol, j);
                    found = 1;
                }
            }
        }

        if (found) {
            return (endrow - startrow + 1) * (endcol - startcol + 1);
        }
        else {
            return 0;
        }
    }

    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = INT_MAX;
        int one, two, three;

        for (int i = 0; i < n; i++) {
            one = minArea(grid, 0, i, 0, m - 1);
            for (int j = 0; j < m; j++) {
                two = minArea(grid, i + 1, n - 1, 0, j);
                three = minArea(grid, i + 1, n - 1, j + 1, m - 1);
                ans = min(ans, one + two + three);
            }
        }

        for (int j = 0; j < m; j++) {
            one = minArea(grid, 0, n - 1, 0, j);
            for (int i = 0; i < n; i++) {
                two = minArea(grid, 0, i, j + 1, m - 1);
                three = minArea(grid, i + 1, n - 1, j + 1, m - 1);
                ans = min(ans, one + two + three);
            }
        }

        for (int j = m - 1; j >= 0; j--) {
            one = minArea(grid, 0, n - 1, j + 1, m - 1);
            for (int i = 0; i < n; i++) {
                two = minArea(grid, 0, i, 0, j);
                three = minArea(grid, i + 1, n - 1, 0, j);
                ans = min(ans, one + two + three);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            one = minArea(grid, i + 1, n - 1, 0, m - 1);
            for (int j = 0; j < m; j++) {
                two = minArea(grid, 0, i, 0, j);
                three = minArea(grid, 0, i, j + 1, m - 1);
                ans = min(ans, one + two + three);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                one = minArea(grid, 0, n - 1, 0, i);
                two = minArea(grid, 0, n - 1, i + 1, j);
                three = minArea(grid, 0, n - 1, j + 1, m - 1);
                ans = min(ans, one + two + three);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                one = minArea(grid, 0, i, 0, m - 1);
                two = minArea(grid, i + 1, j, 0, m - 1);
                three = minArea(grid, j + 1, n - 1, 0, m - 1);
                ans = min(ans, one + two + three);
            }
        }

        return ans;
    }
};
