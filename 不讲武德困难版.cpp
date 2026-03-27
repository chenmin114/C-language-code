#include <stdio.h>
const int mod = 998244353;
long long M[1008611] = {1}; // M[i] 表示 9 的 i 次方取模，用 long long 防止计算时溢出
int size, a[1008611];
long long ans;
int main() 
{
    for ( int i = 1; i < 1e6; i++ ) // 预计算 9 的所有幂
    M[i] = M[i - 1] * 9 % mod;
    for ( char r; (r = getchar()) != EOF; a[size++] = r - '0' );
	// size 表示输入的位数。顺便将读入的数字的实际值（而非 ascii ）存在数组 A 中
    int i;
    for ( i = 0; i < size; i++ ) 
	{
        ans = (ans + (a[i] - (a[i] > 5)) * M[size - i - 1]) % mod; // A[i] >5 时，要把此位为 5 、高位与 n 相同的情况减去
        if ( a[i] == 5 ) // 此位为 5 ，则已经计算了从 0 到 {高位与 n 相同、此位为 4、低位全为 9} 这些数中所有不含 5 的个数。
        break; // 从 {高位与 n 相同、此位为 5 、低位全为 0} 到 n ，这些数的这一位都是 5 ，所以都不会算了，直接结束循环。
    }
// 当算到个位时，我们计算的实际上是 0 到 n - 1 ，还需要判断 n 是否符合题意。
// 如果 i 的值为 size ，那就说明上述循环并没有因为 A[i] == 5 而 break ，从而说明n 没有数位是 5 ，符合题意。
    if ( i == size )
        ans = (ans + 1) % mod;
    printf("%lld\n", ans);
    return 0;
} 
