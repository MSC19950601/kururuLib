#!/usr/bin/ghci
qsort [] = []
qsort (x:xs) = qsort(filter (<x) xs) ++ [x] ++ qsort(filter (>=x) xs)
main = print(qsort [8,9,1,4,7,9,2,3,6,5,4,7,9,5,0])
