
import numpy as np

# ===============================================
#function that computes neighbors for the given point
def neighbors(x):
  result = []
  for i in hamming:
      # if vertices []=0 then there is not such node in the vector.
      # if vertices[x^i] !=0, means there is vetix in the graph with distance 1 or 2
      if vertices[x^i] !=0:
          result.append(x^i) # keep the record of all neighbors (vertices with 1 or 2 distance)
  return result


# ===============================================
# computing simple numbers
# This section computes all possible cases where two 24-bit vertices are having a 1 or 2 hamming 
# distance. For example if u and v are two 24-bit vertices, then the hamming distance btw u and v
# can be computed via x = u XOR v (x = u ^ v) has only 1 or 2 ones in it. Note that if u XOR v = x, # then u XOR x = v. Here, in hamming array, we generate all possible x such that the hamming 
# distance is either 1 or 2.

DEBUG = 0
size = 300 # the total number of possible neighbors for a node with 24-bit is 300
hamming=np.zeros(size, dtype = np.int32)

k=0
for i in range(24):
    for j in range(i,24):
        # The left operands value is moved left by the number of bits specified by the right operand.
        if (DEBUG==0):
          print(" =====")
        mask=1 << i  # left shif bitwise
        if (DEBUG==0):
          print(" m1",i, mask)
        mask2 = 1 << j # left shif bitwise
        if (DEBUG==0):
          print(" m2",j, mask2)
          print(" m3",mask|mask2)
        hamming[k]=mask|mask2 # 
        k=k+1

if (DEBUG==0):
  print("ham:", k)
  print(hamming)

# ===============================================
#reading the data into arrays vertices and index
# The total number of possible vertices that can formed using 24 bits is pow(2,24)

# holds the order of reading(cluster) of each vertix
# we do not use the entire of this vector (only 200000 out of 2^24)
vertices = np.zeros(pow(2,24), dtype=np.int32) 


index=[] # holds the vertices in terms of a digit, in the order of reading 

print(" reading the graph")
with open("clustering_big.txt") as f:
    next(f)
    cluster=1
    for line in f:
        
        curindex=int(line.replace(' ',''), base = 2)  # converts the 24-bit binary vertix to an int
        if (DEBUG==0):
          print("vertices: ", curindex, line)
        index.append(curindex)
        vertices[curindex]=cluster
        cluster=cluster+1

print("length of the index (number of vertices): ", cluster, len(index))


#performing clustering
names=[0] # hold the cluster leader vetix, the first leader is zero

print(" finding the neighbor vertices")

# for each vertix, we find neighbors and clusters
for i in index:
    if (DEBUG==0):
      print("neighbor: ", i)   
    
    # if this vertix has already been observed, or belongs to a cluster, we leave it.
    if vertices[i] in names:
        continue

    nclust=[i]
    while len(nclust)!=0:
        nnclust=[]
        for dot in nclust:
            if (DEBUG==0):
              print("dot: ", dot)
            for ind in neighbors(dot):
                if vertices[ind]!=vertices[i]:
                    nnclust.append(ind)
                    vertices[ind]=vertices[i]
        nclust=nnclust
    names.append(vertices[i])

print(len(names)-1)


