class Trie {
public:
    unordered_map<char, Trie*> m;
    Trie() {

    }

    void insert(string word) {
        Trie* a = this;
        for (int i = 0; i < word.size(); i++) {

            if (a->m[word[i]] == nullptr) {
                a->m[word[i]] = new Trie;
            }

            a = a->m[word[i]];
            //cout << m.size() << endl;
            //cout << "insert" << word[i] << endl;
        }
        a->m['1'];
    }

    bool search(string word) {
        Trie* a = this;
        for (int i = 0; i < word.size(); i++) {
            auto b = a->m.find(word[i]);
            if (b == a->m.end()) {
                //cout<<"没找到"<<word[i]<<endl;
                //cout<<endl;
                return false;
            }
            //cout<<"找到"<<word[i]<<endl;
            a = b->second;
        }
        //cout<<endl;
        if(a->m.find('1')!=a->m.end()){
            return true;
        }
        return false;
    }

    bool startsWith(string word) {
        Trie* a = this;
        for (int i = 0; i < word.size(); i++) {
            auto b = a->m.find(word[i]);
            if (b == a->m.end()) {
                //cout<<"没找到"<<word[i]<<endl;
                //cout<<endl;
                return false;
            }
            //cout<<"找到"<<word[i]<<endl;
            a = b->second;
        }
        //cout<<endl;
        return true;
    }
};