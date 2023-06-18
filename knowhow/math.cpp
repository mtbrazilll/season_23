#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

ll exp(ll b, ll e)
{
        if (e==0) return 1;
        if (e==1) return b;
        ll aux = exp(b,e/2);
        if ( e % 2 == 1) return aux*aux*b;
        return aux*aux;
}

#define max(x, y) (y-x >> 31 & (x^y) ^ y)
#define min(x, y) (y-x >> 31 & (x^y) ^ x)