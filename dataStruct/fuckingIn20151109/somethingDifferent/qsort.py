#!/usr/bin/python2.7
#this is the qsort orig
#used memory is lagure
def qsort(lst):
    lstA=[]
    lstB=[]
    lstrt=[]
    if(len(lst)<=1):
        return lst
    else:
        for i in range(1,len(lst)):
            if (lst[i]<=lst[0]):                #search and append all <= first eml to a new list
                lstA.append(lst[i])
            else:
                lstB.append(lst[i])             #other all append second eml 
        lstrt.extend(qsort(lstA))               #resolv
        lstrt.append(lst[0])
        lstrt.extend(qsort(lstB))
        return lstrt

def quicksort(lst,first,last):
    if first >= last:
        return lst
    i=first
    j=last
    k=lst[first]
    while i<j:
        while i<j and k<=lst[j]: #search one value >= key
            j=j-1
        lst[i]=lst[j]            #move it to first
        while i<j and k>=lst[i]: #search one vaule <= key
            i=i+1                
        lst[j]=lst[i]            #move it to lst[j] the value who moved first

    lst[i]=k                     #resolv key
    quicksort(lst,first,i-1)     #do it again left child right
    quicksort(lst,i+1,last)      #do it again right child list
    return lst

xx = qsort([5,8,9,7,2,1,6,4,9])
for j in xx:
    print j
xxs = [5,9,7,8,2,1,4,7,8,9,6]
print 'orig list'
for j in xxs:
    print j
quicksort(xxs,0,len(xxs)-1)
print 'sorted'
for j in xxs:
    print j
