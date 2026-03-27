#include <stdio.h>

typedef struct 
{
    long long m[2][2];
} Matrix;

Matrix multiply(Matrix a, Matrix b, long long mod) 
{
    Matrix c;
    for (int i = 0; i < 2; i++) 
	{
        for (int j = 0; j < 2; j++) 
		{
            c.m[i][j] = 0;
            for (int k = 0; k < 2; k++) 
			{
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % mod) % mod;
            }
        }
    }
    return c;
}

Matrix matrix_pow(Matrix base, long long exponent, long long mod) 
{
    Matrix result = { { {1, 0}, {0, 1} } };
    while (exponent) 
	{
        if (exponent & 1) 
		{
            result = multiply(result, base, mod);
        }
        base = multiply(base, base, mod);
        exponent >>= 1;
    }
    return result;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, q, p;
        scanf("%lld %lld %lld", &n, &q, &p);
        if (q == 1) {
            printf("%lld\n", (n + 1) % p);
        } else {
            q = (q % p + p) % p;
            Matrix M = { { {1, q}, {0, q} } };
            Matrix M_pow = matrix_pow(M, n, p);
            long long S = (M_pow.m[0][0] + M_pow.m[0][1]) % p;
            printf("%lld\n", S);
        }
    }
    return 0;
}
