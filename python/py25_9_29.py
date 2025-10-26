# # 列表推导式
li=[1,2,3,4,5]
[print(i) for i in li]
li=[]
[li.append(i) for i in range(1,11) if i%2==1] # range(1,11,2) 
print(li)
# 列表嵌套
li=[1,2,3,4,[1,2,3]]
print(li[4])
print(li[4][0])

# # 元组
tua=(1,2,3,'a',[1,2,3])
print(type(tua))
tub=(1) # type int 除非后面加,
# 元组不支持增删改,元组中的列表可以
tua[4].append(4)
print(tua[4])
# 元组的应用场景
name='wan'
age=18
info=(name,age)
print('%s %d'%info) # 必须按顺序
tua[4].append(4)
print(tua[4])

# 字典
# dic={键名：键值，~}
dic={'name':'wan','age':18,'height':1.75}
dic2={'name':'chun','age':18,'height':1.75,'name':'wan'}#  前面的name会被覆盖
print(dic2)
# 字典常见操作
print(dic['age'])
print(dic.get('age'))
dic['age']=20
dic['tel']=10086 # 没有tel,新增
del dic
del dic['height']
# clear 清空但保留
dic.clear()
dic.pop('age')
dic.popitem() # 删除最后一个键

dic={'name':'wan','age':18,'height':1.75}
print(len(dic))
# keys
print(dic.keys())
print(type(dic.keys()))
for i in dic.keys():
    print(i)
# values()
print(dic.values())
print(type(dic['age']))
for i in dic.items():
    print(i,type(i))
print(type(dic.items()))

# 集合的基本格式
s1={'d','f','a','c',1} # 无序的
s2={1,2,3,4,5,1,2,3} # 具有唯一性
a={} # 空字典
b=set() # 空集合
print(type(a))
print(s2)
print(hash(1)) # hash值为本身










































