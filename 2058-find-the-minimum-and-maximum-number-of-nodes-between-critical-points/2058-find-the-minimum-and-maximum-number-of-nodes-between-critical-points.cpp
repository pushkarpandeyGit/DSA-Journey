/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* pre= head;
        int i=1;
        vector<int> v(2,-1);
        vector<int> ans={INT_MAX,-1};
        while(temp->next!=nullptr){
            if( (temp->val>pre->val && temp->val>temp->next->val) || (temp->val<pre->val && temp->val<temp->next->val)){
                if(v[0]==-1) v[0]=i;
                else{
                    if(v[1]!=-1) ans[0]=min(ans[0],i-v[1]);
                    else ans[0]=i-v[0];
                    v[1]=i;
                    ans[1]=v[1]-v[0];
                }
            }
            pre=pre->next;
            temp=temp->next;
            i++;
        }
        if(v[1]==-1) return {-1,-1};
        return ans;
    }
};