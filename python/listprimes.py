##!/usr/bin/env python3

numero=100


def list_primes(k):

    ret=[]
    for n in range(2,k):
        for d in range (2,n//2+1):
            if (n%d)==0:
                break
        else:
            ret.append(n)
    return ret

# print(list_primes(100))



