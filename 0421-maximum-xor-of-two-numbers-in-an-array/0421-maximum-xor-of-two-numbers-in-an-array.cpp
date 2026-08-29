struct Node{
    Node* links[2];

    Node() {
        links[0] = links[1] = nullptr;
    }

    bool iscontain(int n){
        return links[n] != nullptr;
    }

    void put(int n,Node* node){
        links[n]=node;
    }

    Node* get(int n){
        return links[n];
    }
};

class Trie{
private: Node* root;

public:
    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* node=root;

        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;

            if(node->iscontain(bit)==false){
                node->put(bit,new Node());
            }

            node=node->get(bit);
        }
    }

    int maxcontain(int num){
        Node* node=root;
        int maxno=0;

        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;

            if(node->iscontain(1-bit)){
                maxno=maxno|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }

        return maxno;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie obj;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            obj.insert(nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            ans=max(ans,obj.maxcontain(nums[i]));
        }

        return ans;
    }
};