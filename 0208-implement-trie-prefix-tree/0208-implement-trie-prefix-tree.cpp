struct Node {
    vector<Node*> links;
    bool flag;
    Node() {
        links.resize(26, nullptr);
        flag = false;
    }
    bool iscontain(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void charpush(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setend() {
        flag = true;
    }
};

class Trie {
private:
    Node* root;
public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->iscontain(word[i])) {
                node->charpush(word[i], new Node());
            }
            node = node->get(word[i]);  // move node
        }
        node->setend();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->iscontain(word[i])) {
                return false;
            }
            node = node->get(word[i]);  // move node
        }
        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->iscontain(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};