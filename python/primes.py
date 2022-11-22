#!/usr/bin/env python3
for n in range(2,100):
    for d in range (2,n//2+1):
        if (n%d)==0:
            break
    else:
        print(n)

