# 集合常见操作
# 添加元素
# s1={1,2,3,4}
# print(s1)
# s1.add(5)
# s1.add(1)
# s1.update((5,6,7)) # 加入可迭代对象

# 删除元素
# s1.remove(5)
# pop 
# s1.pop() # 删除第一个，字符则随机删除，根据哈希表排
# s1.discard(4)
# print(s1)

# 交集和并集
# a={1,2,3}
# b={2,3,4}
# print(a & b)
# a={'a','b','c'}
# b={'c','d'}
# print(a | b)


# 类型转换
# int() 只能转换纯数字'123'的字符
# a='-1'
# print(type(int(a)))
# print(a)
# print(int(1.7))
# age=int(input('输入年龄')) input默认输入字符类型

# float()
# print(float(12)) # 自动添加一位小数
# print(float('-12.234'))

# str()
# a=[1,2,3]
# print(str(a),type(str(a))) # 任何类型都可以转换,浮点型变字符串末尾0省略

# eval()
# print(eval('10+10')) # 执行运算并返回值
# print(eval('10'+'10'))
# print('ab'+'c')
# eval()可以实现list dict tuple str之间转换
# str1='[[1,2],[3,4],[5,6]]'
# li=eval(str1)
# print(li,type(li))
# str2="{'name':'wan','age':18}"
# dic=eval(str2)
# print(dic,type(dic))

# list()将可迭代对象转化为列表str tuple dict set
# str='abcdef'
# print(list(str))
# print(list((1,2,3,4)))
# print(list({'name':'wan','age':18})) # 只保留键名
# print(list({'a','b','c','d','e'})) # 依然无序

# 深浅拷贝
# import copy
# li=[1,2,3,4,[6,7,8]]
# li3=copy.copy(li) #  浅拷贝
# li2=li # 赋值
# print(li,li2,li3)
# li.append(5)
# li[4].append(2) # 嵌套列表地址一样
# print(li,li2,li3)
# 查看内存地址
# print(id(li),id(li2),id(li3),id(li[4]),id(li3[4]))
# 深拷贝 相当于新增一个变量，地址无关系
# li4=copy.deepcopy(li)
# li[4].append(9)
# print(id(li[4]),id(li4[4]))

# 可变类型 值可变，地址不变 list dict set
# li=[1,2,3,4]
# print(id(li))
# li.append(5)
# print(id(li))
# dic={'name':'wan','age':18}
# print(id(dic))
# dic['age']=19
# print(id(dic))

# 不可变类型
n=10
str='hello'
tua=(1,2,3)
print(id(n),id(str),id(tua))
n+=1 
str='world'
tua=(1,2,3,4)
print(id(n),id(str),id(tua))