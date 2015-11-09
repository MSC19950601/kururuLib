#!/usr/bin/python2.7

def selsort(lst):
    for i in range(0,len(lst)):
        for j in range(i,len(lst)):
            if lst[i]>lst[j]:
                lst[i] = lst[i]^lst[j]
                lst[j] = lst[i]^lst[j]
                lst[i] = lst[i]^lst[j]
    return lst

x=[8,4,3,4,7,9,5,4,2,3,7]
s = 0
for i in x:
    print(i)
    s=s+1
print('____\nall is '+str(s))
s=0
for i in selsort(x):
    print(i)
    s=s+1
print('____\nall is '+str(s))
