import numpy as np


b = [
    [7,9,4,5,3,9],
    [2,8,1,5,4,8],
    [5,7,2,2,6,7],
    [4,6,3,6,7,6],
    [6,9,4,7,8,4]
]
a = np.array(b)

def init_step(i, j, n,p):
    tmp1, tmp2, tmp3 = 0,0,0
    if 0 <= i -1 < n:
        tmp1 = p[i -1, j -1]
    if 0 <= i < n:
        tmp2 = p[i, j -1]
    if 0 <= i + 1 < n :
        tmp3 = p[i + 1, j -1]
    maxtmp =  max(tmp1, tmp2, tmp3)
    if maxtmp == tmp1 :
        return i -1, j -1
    elif maxtmp == tmp2:
        return i , j -1
    elif maxtmp == tmp3 :
        return i + 1, j -1
   

def BaiToanNhatTien(a) :
    p = np.zeros(a.shape)
    p[:,0] = a[:,0]
    # print(p)
    for j in range(1, a.shape[1]) :
        for i in range(a.shape[0]) :
            l,k = init_step(i, j, a.shape[0], p)
            p[i,j] = a[i,j] + p[l,k]
    print(p)
    return p

def Truyvet(a,p,i,j):
    if j != 0 :
        l,k = init_step(i, j, a.shape[0], p)
        if p[i,j] - a[i,j] == p[l,k] :
            Truyvet(a,p,l,k)
        print(l,k)
 


p = BaiToanNhatTien(a)
max_index = np.argmax(p)
i,j = np.unravel_index(max_index, p.shape)
print(i,j)
Truyvet(a,p,i,j)
print(i,j)

