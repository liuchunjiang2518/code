#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
    void printGrid(const std::vector<std::vector<int>>& grid) {
        int max_val = 0;
        for (const auto& row : grid) {
            int row_max = *std::max_element(row.begin(), row.end());
            max_val = std::max(max_val, row_max);
        }

        int width = 1;
        if (max_val != 0) {
            width = std::to_string(max_val).length();
        }

        for (const auto& row: grid) {
            for (size_t j = 0; j < row.size(); ++j) {
                if (row[j] == 0) {
                    std::cout << std::string(width, ' ');
                } else {
                    std::cout << std::setw(width) << row[j];
                }
                
                if (j != row.size() - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }

public:
    void pascalTriangleGrid(int num) {
        std::vector<std::vector<int>> grid(num, std::vector<int>(2 * num, 0));

        for (int i = 0; i < num; ++i) {
            int left_col_index = num - 1 - i;
            int right_col_index = num - 1 + i;

            grid[i][left_col_index] = 1;
            grid[i][right_col_index] = 1;

            if (i > 0) {
                for (int j = left_col_index + 1; j < right_col_index; ++j) {
                    grid[i][j] = grid[i - 1][j - 1] + grid[i - 1][j + 1];
                }
            }
        }

        printGrid(grid);
    }
};

int main() {
    Solution s;
    s.pascalTriangleGrid(12);
    return 0;
}