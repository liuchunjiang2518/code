def max(a,b):
    if(a>b):
        return a
    else:
        return b
a=12
b=13
print(f'{a}和{b}比，{max(a,b)}大')
def test():
    global a
    a=10 # 若要用全局变量a，要先调用test()
    # c=10
    # global c # error先申明，再赋值
def test1(b):
    return b*a
test()
print(test1(2))
def out():
    a=1
    def inn():
        nonlocal a
        a=2
        print(a)
    inn()
    print(a)
out()

# 匿名函数
def add(a,b):
    return a+b # 普通函数

add = lambda a,b:a+b
#  函数名 =lambda 形参，形参：返回值
test =lambda a,b=10:a*b
print(test(1))
funa =lambda :'万春宏'
print(funa())
print(test(1,4))
funa =lambda a,b=10:(a,b)
print(funa(1,2))

a=10
b=20
print(f'{a}<{b}') if a<b else print(f'{a}>={b}')
comp = lambda a,b:f'{a}<{b}' if a<b else f'{a}>={b}'
print(comp(a,b))
# lambda 适合简单逻辑

import builtins
# print(dir(builtins))
# 大写字母开头一般内置常量，小写函数
a=10
b=12
print(abs(a-b))
print(sum([1,2,3])) # 可迭代对象，字符串除外[1,2,3] {1,2,3}
print(max(4,7)) 
print(max(-8,5,key=abs))
li1=[1,2,3]
li2=['a','b']
# print(zip(li1,li2))
tua=zip(li1,li2)
print(list(tua)) 
print(tua)
# for i in zip(li1,li2):
#     print(i)
#     print(type(i))
def funa(a):
    return a*2
mp=map(funa,li1)
# print(mp)
print(list(mp))
for i in map(funa,li1):
    print(i)
    print(type(i))
reduce()
from functools import reduce
# reduce (function,sequnence) function 必须接收两个参数 sequence 序列可迭代对象
def add(x,y):
    return x+y
li=[1,2,3,4]
res=reduce(add,li)
print(res)
li1=[]
for i in range(100):
    li1.append(i)
print(reduce(add,li1))
tua=(1,2,3,4)
tua[0]=9
a,b,c,d=tua

tua=(1,2,3,4)
a,*b =tua
print(b)
def funa(a,b,*args):
    print(a,b)
    print(args,type(args))
funa(1,2,3,4,5,6)
arg=(1,2,3,4)
funa(*arg)