
#include <bits/stdc++.h>
using namespace std;
struct interval
{
    int low;
    int high;
};
struct node{
    interval *i;
    int max;
    node *left;
    node *right;
};

node *newnode(interval i) {
    node *temp = new node;
    temp->i = new interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert (node* root,interval i){
    if (root == NULL) return newnode(i);
 
    int l = root->i->low;
 
    if (i.low < l)root->left = insert(root->left, i);
 
    else root->right = insert(root->right, i);
 
    if (root->max < i.high)root->max = i.high;
 
    return root;

}
bool OVerlap(interval i1, interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high) return true;
    return false;
}
interval *overlapSearch(node *root, interval i)
{
    if (root == NULL) return NULL;
    if (OVerlap(*(root->i), i)) return root->i;
 
    if (root->left != NULL && root->left->max >= i.low)return overlapSearch(root->left, i);
    
    return overlapSearch(root->right, i);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    interval ints[n];
    node *root = NULL;
    for(int i=0;i<n;i++){
        cin>>ints[i].low>>ints[i].high;
        root = insert(root,ints[i]);
        
    }
    
    int n2;
    cin>>n2;
    interval intss[n2];
    for(int i=0;i<n2;i++){
        cin>>intss[i].low>>intss[i].high;
        interval *res = overlapSearch(root, intss[i]);
        if (res == NULL)cout << "No Overlapping Interval"<<endl;
        else cout << "Overlaps with [" << res->low << ", " << res->high << "]"<<endl;;
    }
    return 0;
}
