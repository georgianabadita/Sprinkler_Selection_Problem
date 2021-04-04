from properties import properties
from properties import coord
from functions import *
from time import time
f = open("date.in", "r")
f_w = open("date.out", "w")
first_line = f.readline().strip('\n')
first_line = first_line.split()
width = float(first_line[0])
length = float(first_line[1])
nof_asp = int(first_line[2])
aspensors = []
coords = []
for x in range(nof_asp):
  line = f.readline().strip('\n')
  line = line.split()
  p1 = properties(float(line[0]),float(line[1]))
  c1 = coord(0,0)
  aspensors.append(p1)
  coords.append(c1)

starting(aspensors,coords)
duplicate(aspensors,coords)
start = time()
sorting(coords)
stop = time()
timpScurs = stop - start
print(timpScurs)
for x in coords:
    f_w.write("Prim : " + str(x.prim) + " and final " + str(x.final) + "\n")

greedy(coords)

f_w.close()
