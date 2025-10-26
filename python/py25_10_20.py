import numpy as np
lia=[1,2,3,4]
a=np.array(lia)
print(a*2)
lib=lia*2
print(lib)
lic=[i*2 for i in lia]
print(lic)

a=np.array([1,2,3,4])
b=np.array([5,6,7,8])
c=np.array([[1,2,3,4],[4,5,6,7],[7,8,9,10]])
print(type(a))
print(c.dtype) # int32
print(a.dtype ) # int32
print(a.shape) # (4,)
print(c.shape) # (3,4)
d=np.array([[1,2,3],[4,5,6,7]]) # 元素的形状不一致
print(d.shape)
c.shape=4,3 # 重新分组，变为四个每个元素为3个int的数组
print(c)
c.shape=2,-1 # 分为两组，自动计算数量
print(c)
d=a.reshape((2,-1))
print(d)
print(a)

a=np.arange(12) # 创建一个0~11的数组
b=np.append(a,[12,13])
print(f'{a}\n')
c=np.append(a,[12,13]).reshape(-1,2)
print(f'{c}\n')

# 创建数组
a=np.arange(12)
b=a.reshape((-1,2))
a[1]=100 # 将第二个数组元素改为100
print(a)
print(b) # b的元素也会改变
a=np.arange(0,1,0.1)
print(a)

b=np.linspace(0,1,10) # 开始值，终值，元素个数 含有终值
print(b)
c=np.linspace(0,1,10,endpoint=False)
print(c,'\n')
print(np.linspace(0,0.9,10)) 

print(np.logspace(1,8,num=8,base=2))
print(np.logspace(0,2,3))
np.empty((2,3),np.int)
np.zeros(4,np.float) # 元素类型默认float,可以省略