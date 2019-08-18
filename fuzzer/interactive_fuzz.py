from subprocess import *
import fuzzer
import sys

program_name="./a.out"
print(26,1000)
ans={}
f=ord('A')
r=list(range(26))
fuzzer.rand_gen.shuffle(r)
for i in range(26):
    ans[chr(f+i)]=r[i]
l=list(range(26))
for i in range(26):
    l[ans[chr(f+i)]]=chr(f+i)
ansstr=""
for i in l:
    ansstr+=i

print(ansstr)

def checkio(i):
    if i[0] =='!':
        a=i.split()[1]
        if a==ansstr:
            print("AC")
        else:
            print("WA")
        sys.exit()
        
    elif i[0]=='?':
        x,y=i.split()[1],i.split()[2]
        if ans[x]<ans[y]:
            print("<")
        else:
            print(">")
    else:
        print("WA:Wrong Input")
        sys.exit()
sp = Popen([program_name],stdin=PIPE,stdout=PIPE,stderr=STDOUT)
while True:
    in_str=sp.stdout.readline()
    checkio(in_str)
