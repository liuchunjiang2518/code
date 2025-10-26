print('10'+'10')
firstname='chunhong'
lastname='wan'
print(firstname,lastname,sep=' ')
a='helloworld'
print(a,type(a))
a1=a.encode()
print(a1)
a2=a1.decode()
print(a2)
print('我是谁？\n'*3)
name='helloworld'
print('l' in name) # True
print(name[2]) # l
print(name[0:5]) # 包前不包后，下标0-4
print(name[5:])
print(name[-1])
print(name[-1:-6:-1])
print(name[-1::-1])

# 字符串常见操作
# find find(str,开始查找位置，结束位置) 检测子字符串是否在字符串中，返回开始位置下标，没有返回-1
print(name.find('lo'))
print(name.find('lo',4,9))
print(name.find('lo',0,3))

# index 和find类似，找不到报错
# print(name.index('lo',3,9))

# count
print(name.count('o'))

print(name.startswith('hello')) # 是否以子字符串开头
print(name.endswith('world'))
print(name.replace('world','万春宏')) # replace(str,str,n) n为替换次数
name.replace('world','万春宏')
print(name)

# 列表
List=[1,2,3,4]
print(type(List))
for i in List:
    print(i)
List.append('class')
List.extend('yuu')
List.insert(3,'wo')
List[0]=123
print(123 not in List)
print(List)

names=['wan','chun','hong']
def appendname():
    while True:
        name=input('输入名字')
        if name in names:
            print('名字已存在')
        else:
            names.append(name)
            print(f'已添加{name}')
            break
appendname()
print(names)

li=[1,2,9,3,4,4,2,2]
del li[2]
print(li)
li.remove(2)# 只删一个
li.sort()
li.reverse()
print(li) 

# li=[1,2,3,4,5]
# [print(i) for i in li]
li=[]
for i in range(0,5):
    li.append(i)
    print(li[i])