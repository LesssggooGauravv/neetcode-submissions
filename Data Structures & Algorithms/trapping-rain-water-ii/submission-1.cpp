class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        if (rows == 0) return 0;

        int cols = heightMap[0].size();
        if (cols == 0 || rows < 3 || cols < 3) return 0;

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (r == 0 || r == rows - 1 ||
                    c == 0 || c == cols - 1) {
                    pq.push({heightMap[r][c], r, c});
                    visited[r][c] = true;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int water = 0;

        while (!pq.empty()) {
            auto [height, r, c] = pq.top();
            pq.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols ||
                    visited[nr][nc]) {
                    continue;
                }

                visited[nr][nc] = true;

                if (heightMap[nr][nc] < height) {
                    water += height - heightMap[nr][nc];
                }

                pq.push({
                    max(height, heightMap[nr][nc]),
                    nr,
                    nc
                });
            }
        }

        return water;
    }
};