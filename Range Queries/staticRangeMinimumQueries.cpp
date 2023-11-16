#include<bits/stdc++.h>
using namespace std;

#define int long long

class SegmentTree{
    vector<int> tree;
    int size;

public:
    SegmentTree(vector<int>& array) {
        size=array.size();
        tree.resize(4*size);
        buildTree(array, 0, 0, size-1);
    }
private:
    void buildTree(vector<int>& array, int treeIndex, int left, int right) {
        if(left==right) {
            tree[treeIndex]=array[left];
            return;
        }
        int mid=left+(right-left)/2;
        buildTree(array, 2*treeIndex+1, left, mid);
        buildTree(array, 2*treeIndex+2, mid+1, right);
        tree[treeIndex]=min(tree[2*treeIndex+1], tree[2*treeIndex+2]);
    }

    int query(int treeIndex, int left, int right, int queryLeft, int queryRight) {
        if(queryLeft<=left && right<=queryRight) return tree[treeIndex];

        int mid=left+(right-left)/2;
        int minValue=INT_MAX;
        if(queryLeft<=mid) 
            minValue=min(minValue, query(2*treeIndex+1, left, mid, queryLeft, queryRight));
        if(queryRight>mid)
            minValue=min(minValue, query(2*treeIndex+2, mid+1, right, queryLeft, queryRight));
        return minValue;
    }

public:
    int query(int left, int right) {
        return query(0, 0, size-1, left, right);
    }
};

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> array(n);
    for(int i=0; i<n; i++) cin >> array[i];

    SegmentTree st(array);
    while(q--) {
        int a, b;
        cin >> a >> b;

        cout << st.query(a-1, b-1) << endl;
    }
}
