#define trie MagicDictionary
class MagicDictionary {
    map<int, MagicDictionary*> child;
    bool isLeaf{};
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto& el : dictionary)
            insert(el);
    }
    void insert(string& str) {
        trie* node = this;
        for (int idx = 0; idx < str.size(); ++idx) {
            int cur = str[idx] - 'a';
            if (!node->child.count(cur))
                node->child[cur] = new trie();
            node = node->child[cur];
        }
        node->isLeaf = true;
    }

    bool search(string searchWord) {
        return word_exist_with_one_change(searchWord);
    }
    bool word_exist_with_one_change(string& str) {
        for (int i = 0; i < str.size(); ++i) {
            char cur = str[i];
            for (char chg = 'a'; chg <= 'z'; ++chg) {
                if (chg == str[i])
                    continue;
                str[i] = chg;
                if (word_exist(str))
                    return true;
                str[i] = cur;
              }
            }
        return false;
    }
    
    bool word_exist(string& str, int idx = 0) {
        if (idx == str.size())
            return isLeaf;  // there is a string marked here

        int cur = str[idx] - 'a';
        if (!child.count(cur))
            return false;   // such path doessn't exist
        return child[cur]->word_exist(str, idx + 1);
    }


};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */