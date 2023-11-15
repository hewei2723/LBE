public class Solution {
    public bool IsPalindrome(int x) {
        // 如果 x 是负数或者末尾是 0 且 x 不等于 0，则不可能是回文数
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedNumber = 0;
        int originalNumber = x;

        while (x > 0) {
            int digit = x % 10;
            reversedNumber = reversedNumber * 10 + digit;
            x /= 10;
        }

        return originalNumber == reversedNumber;
    }
}