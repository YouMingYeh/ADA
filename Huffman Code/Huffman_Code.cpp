#include <bits/stdc++.h>
using namespace std;

//listNode
struct listNode {
    int val;
    listNode *left;
    listNode *right;
    listNode(int x) : val(x), left(NULL), right(NULL) {}
};



int n =0;
vector<int> chars;
listNode *t;
vector<listNode *> trees;

bool compare(listNode *a, listNode *b){
    return a->val < b->val;
}
void buildTree()
{
    if(trees.size() <= 1) return;
    sort(trees.begin(), trees.end(), compare);
    listNode * node = new listNode(trees[0]->val+trees[1]->val);
    node->left = trees[0];
    node->right = trees[1];
    trees.erase(trees.begin());
    trees[0] = node;
    // cout << node->val<<endl;
    buildTree();
}
vector< pair<int,string> > ans;

void PrintTree(listNode *t, string str){
    if(!t)return;

    PrintTree(t->left, str + '0');

    if(t->left == NULL && t->right == NULL){
        // cout << t->val <<" "<<str << endl;
        ans.push_back(pair<int,string>(t->val, str));
    }
    PrintTree(t->right, str + '1');
}


void Print(vector< pair<int,string> > ans){
    for(int i=0; i<chars.size(); i++){
        for(int j=0; j<ans.size(); j++){
            if(chars[i] == ans[j].first){
                cout << ans[j].second << endl;
                ans.erase(ans.begin()+j);
                break;
            }
        }
    }
}
int main()
{
    cin >> n;
    if(n == 1) {
        cout<<0;
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        chars.push_back(x);
    }
    for(int i=0; i<n; i++){
        listNode* tree = new listNode(chars[i]);
        trees.push_back(tree);
    }
    buildTree();
    string str = "";
    t = trees[0];
    // cout << t->val;
    PrintTree(t, str);
    Print(ans);

}
