/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    final List<Integer> sortedList = new ArrayList<>();
    
    private final void inorderVisitTree(final TreeNode cur) {
        if (cur.left != null) {
            inorderVisitTree(cur.left);
        }
        sortedList.add(cur.val);
        if (cur.right != null) inorderVisitTree(cur.right);
    }
    public int kthSmallest(TreeNode root, int k) {
        inorderVisitTree(root);
        return sortedList.get(k-1);
    }
}
