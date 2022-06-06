#ifndef C_RAND_RANGE_H
#define C_RAND_RANGE_H

#define SEED 12340
#define MIN 0
#define MAX 4

int rand_range()
{
    return rand() % (MAX + 1 - MIN) + MIN;
}

void ex_c_rand_range()
{
    srand(SEED);
    
    for (int i = 0 ; i < 5; i++) {
        printf("rand_range(): %d\n", rand_range());
    }
}

#endif // C_RAND_RANGE_H