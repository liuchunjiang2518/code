class Stu:
    def __init__(self):
        self.name=input('name:')
        self.age=int(input('age:'))
        self.idnum=input('idnum:')
yuu=Stu()


class Person:
    def __init__(self,obj_name,name,age,tel):
        self.obj_name=obj_name
        self.name=name
        self.age=age
        self.tel=tel
    def introduce(self):    
        print(f'{self.name}的年龄是{self.age}，电话号码是{self.tel}')
    def __del__(self):
        print(f'删除了{self.obj_name}')
pe1=Person('pe1','wanchunhong',18,15708239307)
pe1.introduce()
# pe1.__del__() # 删除实际并未调用
del pe1
print(123)
pe2=Person('pe2','wangukun',99,13696198562)
# 删除对象时，默认调用__del__() 默认在代码最后调用

# 封装
class Stu:
    name='wan' 
    __age=18
    def introduce(self):
        print(f'{self.name}的年龄是{self.__age}')
wan=Stu()
print(wan)
wan.introduce()
print(wan._Stu__age)

# 普通属性 xxx
# 私有属性 _xxx
# 外部可以使用，子类可以继承，但 from xxx import * 中无法使用
# 隐藏属性 __xxx
class Person:
    name='wan'
    __age=18
    _gender='男'
    def __funa(self):
        print(123)
    def _funb(self):
        print(456)
yuu=Person()
print(yuu._gender)
print(yuu._Person__age)
yuu._Person__funa()
yuu._funb()

# 继承
# 类和类继承属性

class Father:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def funa(self):
        print(f'{self.name}:{self.age}')
class Son(Father):
    pass # 占位符，或者None，代码里面类下面不写任何东西，会自动跳过
class Grandson(Son):
    1
    
son=Son('wanchunhong',19)
son.funa()
