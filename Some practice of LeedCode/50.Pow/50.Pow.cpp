#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    
    double qpow(double a, long long b)
	{
        double res = 1;
        while(b)
		{
            if(b&1) res = res*a;//1&1 = 1,others 0 
            b >>= 1;
            a *= a;
        }
        return res;
    }
    
    
    double myPow(double x, long long n) {
        if(n == 0) return 1;
        if(n > 0) return qpow(x,n);
        if(n < 0) return 1/qpow(x,-n);
        return 1.0;
    }
};

int main(int argc, char** argv) {
	return 0;
}
