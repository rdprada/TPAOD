import os
import sys
import fileinput

os.system('rm *.txt')
x = 1 
for filename in os.listdir("."):
	if ('%d.in' %(x)) in filename.lower():
		wc = 0
		textfile = open(filename, 'r')
		for line in textfile:
			temp = line.split()
			wc += len(temp)
		os.system('./../bin/compileBST %d ./benchmark%d.in >> benchmark%d_result.txt' %(wc,x,x))
		x = x + 1
