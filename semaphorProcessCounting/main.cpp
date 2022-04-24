#include <cstdio>
#include <pthread.h>
#include <iostream>

int main()
{
    pthread_t CSem(int K)  cs{ // counting the semaphore which initialized to K
        int val ← K; // this is the value of csem
        BSem gate(min(1, val)); // 1 if val > 0; 0 if val = 0
        BSem mutex(1); // protects the val

        Pc(K) {
            P(gate)
                a1: P(mutex);
            val ← val − 1;
            if val > 0
                V(gate);
            V(mutex);
        }

        Vc(cs) {
            P(mutex);
            val ← val + 1;
            if val = 1
                V(gate);
            V(mutex);
        }
    }
}