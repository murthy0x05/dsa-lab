/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
//     int maxSum = 0;
//     int currSum = 0;
// public:
//     int maxSumBST(TreeNode* root) {
//         int isBST = runMaxSumBST(root);
//         return maxSum;
//     }
//     int runMaxSumBST(TreeNode* root) {
//         if (!root) return 0;
//         int leftSum = runMaxSumBST(root -> left);
//         int sum = 0;
//         if (root -> left && root -> val <= root -> left -> val) {
//             sum = INT_MIN;
//         }
//         if (root -> right && root -> val >= root -> right -> val) {
//             sum = INT_MIN;
//         }
//         if (sum == INT_MIN) {
//             currSum = 0;
//         }

//         int rightSum = runMaxSumBST(root -> right);
        
//         if (leftSum == INT_MIN || rightSum == INT_MIN) {
//             sum = INT_MIN;
//         }
//         if (sum != INT_MIN && leftSum != INT_MIN && rightSum != INT_MIN) {
//             currSum += root -> val;
//             maxSum = max(maxSum, currSum);
//         }
        
//         return sum;
//     }
// };

class TreeData {
public:
    int minValue;
    int maxValue;
    int sum;
    bool isBST;
    TreeData(int min, int max, int sum, bool isBST) {
        minValue = min;
        maxValue = max;
        this->sum = sum;
        this->isBST = isBST;
    }
};
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };


class Solution {
    int maxSum = 0;
public:
    int maxSumBST(TreeNode* root) {
        doTraversal(root);
        return maxSum;
    }
    
    TreeData* doTraversal(TreeNode* root) {
        if (!root) {
            return new TreeData(INT_MAX, INT_MIN, 0, true);
        }
        
        TreeData* leftData = doTraversal(root->left);
        TreeData* rightData = doTraversal(root->right);
        
        bool isBST = leftData->isBST && rightData->isBST &&
                     root->val > leftData->maxValue && 
                     root->val < rightData->minValue;
        
        if (isBST) {
            int currentSum = leftData->sum + rightData->sum + root->val;
            maxSum = max(maxSum, currentSum);
            
            int minVal = (root->left) ? leftData->minValue : root->val;
            int maxVal = (root->right) ? rightData->maxValue : root->val;
            
            return new TreeData(minVal, maxVal, currentSum, true);
        } else {
            return new TreeData(INT_MIN, INT_MAX, 0, false);
        }
    }
};

// class TreeData {
// public:
//     int minValue;
//     int maxValue;
//     bool isBST;
//     TreeData(int min, int max, bool isBST) {
//         minValue = min;
//         maxValue = max;
//         this -> isBST = isBST;
//     }
// };

// class Solution {
//     int maxSum = 0;
//     int currSum = 0;
// public:
//     int maxSumBST(TreeNode* root) {
//         TreeData* treeData = doTraversal(root);
//         return maxSum;
//     }
//     TreeData* doTraversal(TreeNode* root) {
//         if (!root) return nullptr;
//         TreeData* leftTree = doTraversal(root -> left);
//         int minVal = INT_MAX, maxVal = INT_MIN; bool isBST = true;
//         if (root -> left) {
//             maxVal = max(maxVal, leftTree -> maxValue);
//         }

//         if (root -> left && (root -> val <= root -> left -> val || leftTree -> isBST)) {
//             currSum = 0;
//             isBST = false;
//         }

//         TreeData* rightTree = doTraversal(root -> right);
//         if (root -> right) {
//             minVal = min(minVal, rightTree -> minValue);
//         }

//         if (root -> right && (root -> val >= root -> right -> val || rightTree -> isBST)) {
//             currSum = 0;
//             isBST = false;
//         }

//         if (isBST && maxVal < root -> val && minVal > root -> val) {
//             currSum += (root -> val);
//             // cout << root -> val << endl;
//             maxSum = max(maxSum, currSum);
//         } else {
//             currSum = 0;
//         }

//         minVal = min(minVal, root -> val);
//         maxVal = max(maxVal, root -> val);
//         TreeData* currData = new TreeData(minVal, maxVal, isBST);
//         return currData;
//     }
// };