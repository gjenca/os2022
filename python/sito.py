#!/usr/bin/env python3
isprime=[True]*100
isprime[0]=False
isprime[1]=False
for d in range(2,11):
    if not isprime[d]:
        continue
    else:
        for k in range(2*d,100,d):
            isprime[k]=False

for n,yesno in enumerate(isprime):
    if yesno:
        print(n)

