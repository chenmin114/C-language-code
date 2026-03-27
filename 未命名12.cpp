#include <stdio.h>

long long a[3005] = {0};

int main() {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    long long count = 0;
    
    // 固定第一个数 a[i]
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;    // 第二个数的指针
        int right = n - 1;   // 第三个数的指针
        
        while (left < right) {
            long long sum = a[i] + a[left] + a[right];
            
            if (sum == m) {
                // 处理重复元素的情况
                if (a[left] == a[right]) {
                    // 从 left 到 right 的所有组合都满足
                    int cnt = right - left + 1;
                    count += (long long)cnt * (cnt - 1) / 2;
                    break;
                } else {
                    // 统计左右两边相同元素的个数
                    int cnt_left = 1, cnt_right = 1;
                    while (left + 1 < right && a[left] == a[left + 1]) {
                        cnt_left++;
                        left++;
                    }
                    while (right - 1 > left && a[right] == a[right - 1]) {
                        cnt_right++;
                        right--;
                    }
                    count += (long long)cnt_left * cnt_right;
                    left++;
                    right--;
                }
            } else if (sum < m) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    printf("%lld\n", count);
    return 0;
}
