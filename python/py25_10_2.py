def sum(a,b):
    return a+b
print(sum(2,3))

def login():
    print('helloworld')
login()

# return 返回多个值，元组
def buy():
    return '商品',20
    return 15 # 无法执行
print(buy())

a=2
b=3
def swap(a,b,flag=0): # 形参，变量地址不同
    flag=a
    a=b
    b=flag
swap(a,b)
print(a,b) # 结果2，3

def printf(*args): # 元组形式接收
    print(args)
    print(type(args))
printf(1,2,3,4)
def test(**kwargs):
    print(kwargs)
    print(type(kwargs))
test(name='wan',age=19)

def test(a):
    if a==1:
        return a
    else:
        return test(a-1)*a
print(test(4))
# 嵌套定义
# 一个函数中调用另一个函数
def test2(a=0):
    if(a<10):
        a+=1
        print('good')
        test2(a)
test2()
