#include <stdio.h>
#include <time.h>
#include <math.h>

unsigned long long power(int base, int exponent) {
    unsigned long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    time_t t;
    time(&t);
    printf("Timestamp: %ld\n", (long)t);

    int lastTwoDigits = (int)(t % 100);

    time(&t);
    int lastDigit = (int)(t % 10);

    time(&t);
    int anotherTwo = (int)(t % 100);

    unsigned long long r1 = power(lastDigit + 1, lastTwoDigits);
    long hmm = (int)(t % 100);
    unsigned long long hhm = power(hmm, lastDigit);
    unsigned long r2 = power(anotherTwo, lastDigit * hhm);
    r1 = r1 / pow(10, (int)(log10(r1)) - 1);
    r2 = r2 / pow(10, (int)(log10(r2)) - 1);
    time(&t);
    unsigned long long random;
    long long oneMoreLastDigit = (int)(t % 10);
    r1 +=1;
    r2 +=1;
    if (oneMoreLastDigit == 1 || oneMoreLastDigit == 9) {
        random = r1 / r2;
    } else if (oneMoreLastDigit == 2 || oneMoreLastDigit == 8) {
        random = r1 * r2;
    } else if (oneMoreLastDigit == 3 || oneMoreLastDigit == 7) {
        random = r1 + r2;
    } else if (oneMoreLastDigit == 4 || oneMoreLastDigit == 6) {
        random = r1 - r2;
    } else if (oneMoreLastDigit == 5) {
        random = r1 * r2 + r1 / r2;
    } else if (oneMoreLastDigit == 0) {
        random = 0;
    }

    printf("Random number: %lld\n", random);

    return 0;
}
