class pos {
public:
    int i;
    int j;
    pos(int i, int j) {
        this->i = i;
        this->j = j;
    }
    bool operator== (const pos& a) const {
        if (this->i == a.i && this->j == a.j) {
            return true;
        }
        return false;
    }
};

namespace std {
    template<> struct hash<pos> {
        size_t operator()(const pos& p) const {
            // 组合多个成员的哈希值（避免单一成员哈希冲突）
            size_t hash_i = hash<int>()(p.i);
            size_t hash_j = hash<int>()(p.j);
            // 异或 + 移位减少冲突（也可使用更优的组合方式，如 boost::hash_combine）
            return hash_i ^ (hash_j << 1);
        }
    };
}
class Solution {
public:

    string s;
    unordered_set<pos> set;
    bool exist(vector<vector<char>>& board, string word) {
        s = word;
        int b[70];
        int w[70];
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                b[board[i][j] - 'A']++;
            }
        }
        for (int i = 0; i < word.size(); i++) {
            w[word[i] - 'A']++;
        }
        for (int i = 0; i < 70; i++) {
            if (w[i] > b[i]) {
                return false;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backTrack(board, i, j, 0)) {
                    return true;
                }

            }
        }
        return false;
    }
    bool backTrack(vector<vector<char>>& board, int i, int j, int k) {
        if (board[i][j] != s[k] || set.find(pos(i, j)) != set.end()) {
            return false;
        }
        set.insert(pos(i, j));
        if (k == s.size() - 1) {
            return true;
        }
        bool a, b, c, d;
        if (i > 0) {
            a = backTrack(board, i - 1, j, k + 1);
            if (a) {
                return true;
            }
        }
        if (i < board.size() - 1) {
            b = backTrack(board, i + 1, j, k + 1);
            if (b) {
                return true;
            }
        }
        if (j > 0) {
            c = backTrack(board, i, j - 1, k + 1);
            if (c) {
                return true;
            }
        }
        if (j < board[0].size() - 1) {
            d = backTrack(board, i, j + 1, k + 1);
            if (d) {
                return true;
            }
        }
        set.erase(pos(i, j));
        return false;
    }

};