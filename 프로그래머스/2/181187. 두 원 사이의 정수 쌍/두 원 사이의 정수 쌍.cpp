#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long R1 = r1;
    long long R2 = r2;
    long long ans = 0;

    for (long long x = 1; x <= R2; ++x) {
        long long xx = x * x;

        long long outer = R2*R2 - xx;
        long long y_max = (long long)floor(sqrt((long double)outer));
        while ((y_max+1) * (y_max+1) <= outer) y_max++;
        while (y_max*y_max > outer) y_max--;

        long long inner = R1*R1 - xx;
        long long y_min = 0;

        if (inner > 0) {
            long long t = (long long)floor(sqrt((long double)inner));
            while ((t+1)*(t+1) <= inner) t++;
            while (t*t > inner) t--;

            if (t*t == inner) y_min = t;
            else y_min = t + 1;
        } else {
            y_min = 0;
        }

        if (y_min <= y_max) {
            ans += (y_max - y_min + 1);
        }
    }

    return ans*4;
}
