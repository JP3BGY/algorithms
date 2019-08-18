#!/usr/bin/env python3
from collections import deque
import random
import sys

rand_gen=random.SystemRandom()

def gen_graph(v,e,is_directed=False):
    es=set()
    while len(let) < e:
        a=rand_gen.randrange(v)
        b=a
        while b==a:
            b=rand_gen.randrange(v)
        if is_directed == False:
            if (b,a) in es:
                continue
        es.add((a,b))
    return list(es)
    
def gen_tree(n,is_directed=False):
    ret=deque()
    for i in range(n-1):
        a=rand_gen.randrange(i+1)
        ret.append((a,i+1))
    if is_directed == False:
        ret2=deque()
        for tmp in ret:
            if rand_gen.randrange(2)==0:
                tmp=(tmp[1],tmp[0])
            ret2.appendleft(tmp)
        ret=ret2
    return list(ret)

def gen_connected_graph(v,e):
    ret=gen_tree(v)
    ret=set(ret)
    while len(ret) < e:
        a=rand_gen.randrange(v)
        b=a
        while b==a:
            b=rand_gen.randrange(v)
        if (b,a) in ret:
            continue
        ret.add((a,b))
    return list(ret)

def gen_rand_list(n,l,r):
    ret = []
    for i in range(n):
        ret.append(rand_gen.randint(l,r))
    return ret

def print_tuple(t,num_map=lambda n:n,is_started_by_one=False,weight_len=0,weight_max=0):
    for i in t:
        i=num_map(i)
        if is_started_by_one:
            i+=1
        print(i,end=" ")
        print(i,end=" ",file=sys.stderr)
    for i in range(weight_len):
        print(rand_gen.randrange(weight_max+1),end=" ")
        print(rand_gen.randrange(weight_max+1),end=" ",file=sys.stderr)
    print("")
    print("",file=sys.stderr)

def print_list(l,is_started_by_one=False,weight_len=0,weight_max=0,f_numrandom=False,num_max=0,f_shuffle=False):
    if f_shuffle:
        rand_gen.shuffle(l)
    num_map=lambda n:n
    if f_numrandom:
        mapping=list(range(num_max))
        num_map=lambda n:mapping[n]
    for i in  l:
        if isinstance(i,tuple):
            print_tuple(i,num_map,is_started_by_one,weight_len,weight_max)
        else:
            print(i,end=" ")
            print(i,end=" ",file=sys.stderr)
    print("")
    print("",file=sys.stderr)
if __name__ == '__main__':
    H=rand_gen.randint(1,1000)
    W=rand_gen.randint(1,1000)
    print(H,W)
    for i in range(H):
        for j in range(W):
            if rand_gen.randint(0,1):
                print(".",end="")
            else:
                print("#",end="")
        print()




