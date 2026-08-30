struct Node{
    Node* links[2];
    Node() {
        links[0] = links[1] = nullptr;
    }
    bool iscontain(int n){
        if(links[n]==nullptr) return false;
        return true;
    }
    void put(int n,Node* node){
        links[n]=node;
    }
    Node* get(int n){
        return links[n];
    }
};
class Trie{
private: 
    Node* root;
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
     int maxxor(int num){
        Node* node=root;
        int maxi=0;

        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;

            if(node->iscontain(1-bit)){
                maxi=maxi|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }

        return maxi;
    }

};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> q;

        for(int i=0;i<queries.size();i++){
            int x = queries[i][0];
            int m = queries[i][1];
            q.push_back({m,{x,i}});
        }

        sort(q.begin(),q.end());
        Trie obj;
        vector<int> ans(queries.size());

        int j = 0;
        for(auto it:q){
            int m = it.first;
            int x = it.second.first;
            int ind = it.second.second;
            while(j<nums.size() && nums[j]<=m){
                obj.insert(nums[j]);
                j++;
            }
            if(j==0) ans[ind] = -1;
            else ans[ind] = obj.maxxor(x);
        }

        return ans;
    }
};