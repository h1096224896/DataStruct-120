public class demo {

    // 最长公共子序列
    public static int LCSlength(String a, String b) {
        int m = a.length();
        int n = b.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 两个字符相等,取左上角的值加1
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]); // 两个字符不等，取左边或者上边的最大值
                }
            }
        }
        return dp[m][n];
    }

    // 编辑距离
    public static int editDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        // 创建一个二维数组来存储子问题的解
        int[][] dp = new int[m + 1][n + 1];
        // 初始化边界条件：将空字符串转换为另一字符串需要的操作数
        for (int i = 0; i <= m; i++)
            dp[i][0] = i; // 删除所有字符
        for (int j = 0; j <= n; j++)
            dp[0][j] = j; // 插入所有字符
        // 填充dp表格
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1]; // 如果字符相同，则不需要额外操作,等于左上角的值
                else
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1; // 三种操作，取最小值
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) {
        System.out.println(LCSlength("hanjiahui", "jia"));
        System.out.println(editDistance("horse", "ros"));
    }
}