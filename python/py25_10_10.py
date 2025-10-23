# 递归
# def funa(a):
#     if(a==1):
#         return 1
#     return a*funa(a-1)
# print(funa(3))

# def add():
#     s=0
#     for i in range(1,101):
#         s+=i
#     return s
# print(add())

# def funb(a):
#     if(a==1):
#         return 1
#     return a+funb(a-1)
# print(funb(100))

#斐波那契数列
# def funa(a):
#     if(a<=2):
#         return 1
#     return funa(a-1)+funa(a-2)
# print(funa(6))

# 闭包
# 函数嵌套 内层使用外层变量 外层返回值是内层函数名
# def funout(b):
#     a=10
#     def funin():
#         print(a*b)
#     return funin # 不加小括号是因为funin参数比较多时或受到限制时，写法不规范
# # print(funout()) # 内部函数地址
# funout(20)()
# ot=funout(20)
# ot()

# a=1
# b=1
# print(id(a))
# print(id(b))
# a=2
# print(id(a))
# def funa(a):
#     return a*2
# print(id(funa(1)))
# print(id(2))
# print(funa)
# print(id(funa))
# print(id(funa(2)))

# def funout(m):
#     print(m)
#     def funin(n):
#         print(n)
#         return m+n
#     return funin
# ot=funout(10)
# ot(20)
# print(ot(20))
# print(ot(30))
# 外函数被调用一次后，每次调用内函数，闭包变量只有一份 例子，m只被print了一次

# def funb():
#     print('发消息')

# def funa(fn):
#     print('开始注册')
#     print('登录')
#     fn()
# funa(funb)
# 装饰器
# send 被装饰的函数
def send():
    print('发消息')
# send()
def funout(fn):
    def funin():
        print('开始注册')
        print('登录')
        fn()
    return funin
funout(send)()































































































































