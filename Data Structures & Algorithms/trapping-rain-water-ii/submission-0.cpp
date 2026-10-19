class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size(),cols=heightMap[0].size();
        int size=rows*cols;
        vector<int>dist(size,20001);
        vector<vector<int>>buckets(20001);
        int ans=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(r==0||r==rows-1||c==0||c==cols-1){
                    int p = r*cols+c;
                    dist[p]=heightMap[r][c];
                    buckets[dist[p]].push_back(p);
                }
            }
        }
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int cost=0;cost<20001;cost++){
            while(!buckets[cost].empty()){
                int p = buckets[cost].back();
                buckets[cost].pop_back();

                if(dist[p]!=cost) continue;
                
                ans+=cost-heightMap[p/cols][p%cols];
                int r=p/cols,c=p%cols;
                for(int d=0;d<4;d++){
                    int rr = r+dr[d];
                    int cc = c+dc[d];
                    if(rr>=0 && rr<rows && cc>=0 && cc<cols){
                        int q = rr*cols+cc;
                        int next = max(cost,heightMap[rr][cc]);
                        if(next<dist[q]){
                            dist[q]=next;
                            buckets[next].push_back(q);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
