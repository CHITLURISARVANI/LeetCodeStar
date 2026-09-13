class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        int m = image.size();
        int n = image[0].size();

        // Out of bounds
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Stop if this pixel is not the original color
        if (image[r][c] != oldColor)
            return;

        // Change the color
        image[r][c] = newColor;

        // Visit 4 adjacent pixels
        dfs(image, r + 1, c, oldColor, newColor); // down
        dfs(image, r - 1, c, oldColor, newColor); // up
        dfs(image, r, c + 1, oldColor, newColor); // right
        dfs(image, r, c - 1, oldColor, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        // Important: if both colors are same, nothing needs to change
        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};