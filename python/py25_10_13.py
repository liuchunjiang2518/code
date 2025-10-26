def outer(fn):
    def inner():
        fn()
        print(456)
    return inner

# 语法糖
@outer
def send():
    print(123)
send()

# 被装饰的函数有参数
def outer(fn):
    def inner(name):
        print('A')
        fn(name)
    return inner

@outer
def funa(a):
    print(a)
funa('B')
outer(funa)('B')

def outer(fn):
    def inner(*args,**kwargs):
        fn(*args,**kwargs)
    return inner

@outer
def funa(*args,**kwargs):
    print(args)
    # print('\n')
    print(kwargs)
a={'name':'wan','age':18}
b=(1,2,3)
funa('123',a,b,'456',name='wan',age=18)

def deco1(fn):
    def inner():
        return 'A'+'B'+fn()+'C'+'D'
    return inner
def deco2(fn):
    def inner():
        return 'E'+'F'+fn()+'G'+'H'
    return inner
def deco3(fn):
    def inner():
        return 'I'+'J'+fn()+'K'+'L'
    return inner

@deco1
@deco2
@deco3
def send():
    return 'M'
print(send())
# 输出结果ABEFIJMKLGHCD

# 面向对象基础

# 面向过程，一个个步骤，即一个个函数
# 面向对象，实现一个功能，看重谁来做
# 类和对象,类是同一属性的一类事物的统称，类名，属性，方法：对象具有的功能
# 对象是类的具体体现
class Stu:
    age=18
print(Stu.age)
# 新增类属性
Stu.height=1.85
print(Stu.height)

# 实例化对象
yuu=Stu()
sub=Stu()
print(yuu,sub,sep='\n') # 对象在内存的地址

class Stu:
    age=18
    name='万春宏'
    def funb(self):
        print(f'{Stu.name}:{self.age}')
    def funa(self): # self即对象
        print('万春宏',self,sep= '\n')
yuu=Stu()
print(yuu)
yuu.age=19
# 类属性一类都具有，实例属性单独
yuu.funa()
yuu.funb()
yuu.gender='男'
print(yuu.gender)

class Stu:
    age=0
    name='未命名'
    height=1.85
    def __init__(self):
        print('正在实例化')
        #实例化对象
        self.name=input()
        self.age=int(input())
        self.height=float(input())
Yuu=Stu()

