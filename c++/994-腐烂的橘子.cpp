class pos {
public:
    int x;
    int y;
    bool operator==(const pos& a) const {
        if (this->x == a.x && this->y == a.y) {
            return true;
        }
        return false;
    }
    pos(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

namespace std {
    template<>
    struct hash<pos> {
        size_t operator()(const pos& p) const {
            return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
        }
    };
}

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        unordered_set<pos>* set1=new unordered_set<pos>;
        unordered_set<pos>* set2 = new unordered_set<pos>;
        int time = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    set1->insert(pos(j, i));
                }
            }
        }
        if(set1->size()!=0){
            time--;
        }
        //cout<<"腐烂橘子插入完成"<<endl;
        for (; set1->size() != 0; time++) {
            for (pos i : *set1) {
                if (i.x > 0) {
                    if(grid[i.y][i.x-1]==1){
                        grid[i.y][i.x-1]=2;
                        set2->insert(pos(i.x - 1, i.y));
                    }

                }
                if (i.x < grid[0].size() - 1) {
                    if(grid[i.y][i.x+1]==1){
                        grid[i.y][i.x+1]=2;
                        set2->insert(pos(i.x + 1, i.y));
                    }

                }
                if (i.y > 0) {
                    if(grid[i.y-1][i.x]==1){
                        grid[i.y-1][i.x]=2;
                        set2->insert(pos(i.x, i.y - 1));
                    }

                }
                if (i.y < grid.size() - 1) {
                    if(grid[i.y+1][i.x]==1){
                        grid[i.y+1][i.x]=2;
                        set2->insert(pos(i.x, i.y + 1));
                    }

                }
            }
            //cout<<time<<"min"<<endl;
            auto temp = set1;
            set1 = set2;
            set2 = temp;
            set2->clear();
            //cout<<set1->size()<<endl;
            //cout<<set2<<endl;
        }
        //cout<<"开始遍历矩阵"<<endl;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};

