#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class GfG {

    public static Node lca2(Node root ,int n1,int n2){
        if(root == null || root.data == n1 || root.data == n2){
            return root;
        }
        Node leftLca = lca2(root.left,n1,n2);
        Node rightLca = lca2(root.right,n1,n2);
        if(rightLca == null){
            return leftLca;
        }
        if(leftLca == null){
            return rightLca;
        }
        return root;
    }
    public static int lcaDist(Node root ,int n){
        if(root == null){
            return -1;
        }
        if(root.data == n){
            return 0;
        }
        int leftDist = lcaDist(root.left,n);
        int rightDist = lcaDist(root.right,n);
        if(leftDist ==-1 && rightDist ==-1){
            return -1;
        }
        else if(leftDist ==-1){
            return rightDist+1;
        }
        else {
            return leftDist+1;
        }
    }
    int findDist(Node root, int a, int b) {
        // Your code here
        Node lca = lca2(root,a,b);
        int dist1 = lcaDist(lca,a);
        int dist2 = lcaDist(lca,b);
        return dist1+dist2;
    }
}

int main()
{
    return 0;
}
