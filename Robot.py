import numpy as np
def Check(i,rows):
    if i <0 :
        return 0
    elif i>=rows:
        return rows-1
    return i

a=np.array([
    [7,9,4,5,3,9],
    [2,8,1,5,4,8],
    [5,7,2,2,6,7],
    [4,6,3,6,7,6],
    [6,9,4,7,8,4]]) 
f= np.zeros((5,6))
f[:,0] = a[:,0]
print(a)
print(f)
rows, clolumn = a.shape
for i in range(1,clolumn):
    for j in range(rows):
        f[j][i]+=a[j][i] + max(f[Check(j-1,rows)][i-1],
                               f[Check(j,rows)][i-1],
                               f[Check(j+1,rows)][i-1])
max  = np.argmax(f[:, clolumn-1:])
print(f)
print(f" max :  {max}")
for i in range(clolumn-1,-1,-1):
    temp =f[max][i]- a[max][i] 
    print(max,i)
    if(temp!=0 and i!=1):
        # cap nhat max
        for j in range(rows-1,-1,-1):
            if(f[j][i-1] == temp):
                max = j
                break

#print(temp)