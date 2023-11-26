class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false){}
};

class WordDictionary {
private: 
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for(char ch : word)
        {
            if(current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchNode(root, word, 0);
    }
private:
    bool searchNode(TrieNode* node, string& word, int idx)
    {
        if(idx == word.size())
        {
            return node->isEndOfWord;
        }
        char ch = word[idx];
        if(ch == '.')
        {
            for(auto& p : node->children)
            {
                if(searchNode(p.second, word, idx + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            if(node->children.find(ch)==node->children.end())
            {
                return false;
            }
            TrieNode* child = node->children[ch];
            return searchNode(child, word, idx+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */