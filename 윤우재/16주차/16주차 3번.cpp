class TrieNode{
public
    unordered_mapchar, TrieNode children;
    bool isEndOfWord;

    TrieNode()  isEndOfWord(false){}
};

class Trie {
private
    TrieNode root;
public
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode current = root;
        for(char ch  word)
        {
            if(current-children.find(ch) == current-children.end())
            {
                current-children[ch] = new TrieNode();
            }
            current = current-children[ch];
        }
        current-isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode node = searchNode(word);
        return (node != nullptr && node-isEndOfWord);
    }
    
    bool startsWith(string prefix) {
        return(searchNode(prefix)!=nullptr);
    }

private
    TrieNode searchNode(string word)
    {
        TrieNode current = root;
        for(char ch  word)
        {
            if(current-children.find(ch) == current-children.end())
            {
                return nullptr;
            }
            current = current-children[ch];
        }
        return current;
    }
};


  Your Trie object will be instantiated and called as such
  Trie obj = new Trie();
  obj-insert(word);
  bool param_2 = obj-search(word);
  bool param_3 = obj-startsWith(prefix);
 