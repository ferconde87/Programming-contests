class Solution {
    public int sumNumbers(TreeNode A) {
        return SumNumbersHelper(A,0)%1003;
    }
    private int SumNumbersHelper(TreeNode A, int number){
        int currentNumber = (number%1003) * 10 + A.val;
        if(A.left == null && A.right == null) return currentNumber;
        int leftSide = A.left == null ? 0:SumNumbersHelper(A.left, currentNumber);
        int rightSide = A.right == null ? 0:SumNumbersHelper(A.right, currentNumber);
        return leftSide + rightSide;
    }
}