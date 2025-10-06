#include <stdio.h>
#include <string.h>

int longestRepeatingSubsequence(char* str) {
    int n = strlen(str);
    int dp[n+1][n+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          
            if (str[i-1] == str[j-1] && i != j) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
               
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    return dp[n][n];
}

void printLRS(char* str) {
    int n = strlen(str);
    int dp[n+1][n+1];

    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++) 
            dp[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i-1] == str[j-1] && i != j) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    int index = dp[n][n];
    char lrs[index + 1];
    lrs[index] = '\0';

    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (str[i-1] == str[j-1] && i != j) {
            lrs[index-1] = str[i-1];
            i--;
            j--;
            index--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Repeating Subsequence: %s\n", lrs);
}

int main() {
    char str[] = "AABCBDC";

    printf("Input string: %s\n", str);
    printLRS(str);

    return 0;
}
                                                                       