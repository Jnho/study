#CSV(Comma-Separated Values)
#TSV(Tab) , SSV(Space)
#1. 한 줄에 데이터 하나, 한 줄에는 쉼표로 속성 구분
#2. 첫 번째 줄은 헤더로 사용 가능

csv="""\
p,x,s,n,t,p,f,c,n,k,e,e,s,s,w,w,p,w,o,p,k,s,u
e,x,s,y,t,a,f,c,b,k,e,c,s,s,w,w,p,w,o,p,n,n,g
e,b,s,w,t,l,f,c,b,n,e,c,s,s,w,w,p,w,o,p,n,n,m
p,x,y,w,t,p,f,c,n,n,e,e,s,s,w,w,p,w,o,p,k,s,u
e,x,s,g,f,n,f,w,b,k,t,e,s,s,w,w,p,w,o,e,n,a,g
e,x,y,y,t,a,f,c,b,n,e,c,s,s,w,w,p,w,o,p,k,n,g
e,b,s,w,t,a,f,c,b,g,e,c,s,s,w,w,p,w,o,p,k,n,m
e,b,y,w,t,l,f,c,b,n,e,c,s,s,w,w,p,w,o,p,n,s,m
p,x,y,w,t,p,f,c,n,p,e,e,s,s,w,w,p,w,o,p,k,v,g
e,b,s,y,t,a,f,c,b,g,e,c,s,s,w,w,p,w,o,p,k,s,m
e,x,y,y,t,l,f,c,b,g,e,c,s,s,w,w,p,w,o,p,n,n,g
e,x,y,y,t,a,f,c,b,n,e,c,s,s,w,w,p,w,o,p,k,s,m
e,b,s,y,t,a,f,c,b,w,e,c,s,s,w,w,p,w,o,p,n,s,g
p,x,y,w,t,p,f,c,n,k,e,e,s,s,w,w,p,w,o,p,n,v,u\
"""
splitted=csv.split("\n")
for item in splitted:
    list_mushroom=item.split(",")
    print(list_mushroom)
    #요소 하나 선택
    print(list_mushroom[0])
    print(list_mushroom[1])
    print(list_mushroom[-1])    #마지지막 요소
    print(list_mushroom[-2])    #마지막에서 두번째 요소

    #범위 선택
    print(list_mushroom[1:4])   #1~4번째 
    print(list_mushroom[5:10])
    print(list_mushroom[:10])   #처음부터 10번째 까지
    print(list_mushroom[5:])   #5번째 부터 마지막 까지
    