#!/usr/bin/python2.7

def sort(lst):
    for i in range(0,len(lst)):
        for j in range(0,len(lst)-i-1):
            if lst[j] > lst[j+1]:
                lst[j] = lst[j]^lst[j+1]
                lst[j+1] = lst[j]^lst[j+1]
                lst[j] = lst[j]^lst[j+1]
    return lst

def main():
    x = [8,4,7,5,6,3,2,1,4,8,4,5,7,5,2,1,4,7]
    s = 0
    for i in x:
        print(i)
        s=s+1
    print('___\nall is ' +str(s))
    s = 0
    print('______________')
    for i in sort(x):
        print(i)
        s=s+1
    print('____\nall is '+str(s))
    return

main()
