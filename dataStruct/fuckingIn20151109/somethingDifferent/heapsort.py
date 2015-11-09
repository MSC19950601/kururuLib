#!/usr/bin/python2.7
#heap sort
#firt we need create and adjust it
def heapadjust(lst,parent,length):
    temp = lst[parent]
    child = 2*parent+1    #child node is 2*parent+1
    while child<length:
        if child+1 < length and lst[child] < lst[child+1] :
            child = child+1
        if temp >= lst[child]:
            break
        lst[parent] = lst[child]
        parent = child
        child = 2*parent + 1
    lst[parent] = temp
def heapsort(lst):
    topNode = []
    i = len(lst)/2-1
    while i>=0:
        heapadjust(lst,i,len(lst))
        i=i-1
    i = len(lst)-1
    while i>=0:
        topNode.append(lst[0])
        lst[0] = lst[0]^lst[i]
        lst[i] = lst[0]^lst[i]
        lst[0] = lst[0]^lst[i]
        heapadjust(lst,0,i)
        i=i-1
    return topNode
xx = [5,7,8,6,5,4,7,1,1,3,5]
for i in xx:
    print i
print '__________'
for i in heapsort(xx):
    print i

