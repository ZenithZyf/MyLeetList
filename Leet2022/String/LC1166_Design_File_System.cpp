class FileSystem {
    struct TrieNode {
        TrieNode* branches[27] = {nullptr};
        int value = -1;
    };
public:
    TrieNode* root;
    TrieNode* current;
    int index_of_last_slash;
    
    FileSystem() {
        root = new TrieNode();
        root->value = 0;
    }
    
    bool createPath(string path, int value) {
        current = root;
        int size = path.length();
        index_of_last_slash = path.find_last_of('/');
        if (!hasParentPath(path)) {
            return false;
        }
        for (int i = index_of_last_slash; i < size; ++i) {
            int index = getIndexInTrieBranch(path[i]);
            if (current->branches[index] == nullptr) {
                current->branches[index] = new TrieNode();
            }
            current = current->branches[index];
        }
        
        if (current->value != -1) {
            return false;
        }
        current->value = value;
        return true;
    }
    
    int get(string path) {
        current = root;
        int size = path.length();
        for (int i = 0; i < size; ++i) {
            int index = getIndexInTrieBranch(path[i]);
            if (current->branches[index] == nullptr) {
                return -1;
            }
            current = current->branches[index];
        }
        return current->value;
    }
    
    bool hasParentPath(string path) {
        for (int i = 0; i < index_of_last_slash; ++i) {
            int index = getIndexInTrieBranch(path[i]);
            if (current->branches[index] == nullptr) {
                return false;
            }
            current = current->branches[index];
        }
        return current->value != -1;
    }
    
    int getIndexInTrieBranch(char ch) {
        return ch != '/' ? ch - 'a' : 26;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
