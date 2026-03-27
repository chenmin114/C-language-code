#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_S1_LEN 50010
#define MAX_S2_LEN 55

char s1[MAX_S1_LEN], s2[MAX_S2_LEN];
char tokens[MAX_S2_LEN][MAX_S2_LEN]; // 存储拆分后的 token
int token_count;
int star_start, star_end; // s2 是否以 * 开头/结尾

// 拆分 s2 为 tokens
void split_tokens() {
    token_count = 0;
    int len = strlen(s2);
    int i = 0;
    while (i < len) {
        if (s2[i] == '*') {
            i++;
            continue;
        }
        int j = i;
        while (j < len && s2[j] != '*') {
            j++;
        }
        int tok_len = j - i;
        strncpy(tokens[token_count], s2 + i, tok_len);
        tokens[token_count][tok_len] = '\0';
        token_count++;
        i = j;
    }
    // 判断首尾是否为 *
    star_start = (s2[0] == '*');
    star_end = (len > 0 && s2[len - 1] == '*');
}

// 在 s1 中从 start 位置开始找 token，返回匹配的起始位置，找不到返回 -1
int find_token(int start, const char *token) {
    int len = strlen(token);
    int s1_len = strlen(s1);
    if (start + len > s1_len) return -1;
    for (int i = start; i <= s1_len - len; i++) {
        if (strncmp(s1 + i, token, len) == 0) {
            return i;
        }
    }
    return -1;
}

// 检查从 s1 的 pos 开始是否能匹配整个模式
int match_pattern(int pos) {
    int current_pos = pos;
    int s1_len = strlen(s1);
    
    // 如果不以 * 开头，第一个 token 必须匹配起始位置
    if (!star_start) {
        if (strncmp(s1 + current_pos, tokens[0], strlen(tokens[0])) != 0) {
            return 0;
        }
        current_pos += strlen(tokens[0]);
    }
    
    // 匹配中间的 tokens
    int start_idx = star_start ? 0 : 1;
    for (int i = start_idx; i < token_count - (star_end ? 0 : 1); i++) {
        int found = find_token(current_pos, tokens[i]);
        if (found == -1) return 0;
        current_pos = found + strlen(tokens[i]);
    }
    
    // 如果不以 * 结尾，最后一个 token 必须匹配结束位置
    if (!star_end && token_count > 0) {
        int last_idx = token_count - 1;
        int last_len = strlen(tokens[last_idx]);
        if (current_pos != s1_len - last_len) {
            return 0;
        }
        if (strncmp(s1 + (s1_len - last_len), tokens[last_idx], last_len) != 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", s1, s2);
        split_tokens();
        
        int s1_len = strlen(s1);
        int s2_len = strlen(s2);
        int result[MAX_S1_LEN], result_count = 0;
        
        // 如果 s2 全是 *，则每个位置都可以匹配
        if (token_count == 0) {
            for (int i = 0; i <= s1_len - 1; i++) {
                result[result_count++] = i + 1;
            }
        } else {
            // 否则尝试每个可能的起始位置
            for (int start = 0; start <= s1_len - 1; start++) {
                if (match_pattern(start)) {
                    result[result_count++] = start + 1;
                }
            }
        }
        
        printf("%d\n", result_count);
        if (result_count > 0) {
            for (int i = 0; i < result_count; i++) {
                printf("%d ", result[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
