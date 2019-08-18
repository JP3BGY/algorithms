while True:
    try:
        i,j=map(int,input().split())
        k=float(input())
        print(i+j,",",k)

    except EOFError:
        break
