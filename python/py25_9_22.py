# a=1
# b=12
# print(f'{a}小于或等于{b}') if a<=b else print(f'{a}大于{b}')

# ticket=int(input('是否有票'))
# if ticket==True:
#     age=int(input('是否成年'))
#     if age>=18:
#         print('收费50')
#     elif age<18:
#         print('收费25')
# elif ticket==False:
#     print('请购票')
# else:
#     print('error')

# def fact(n):
#     if n==1:
#         return 1
#     return n*fact(n-1)
# print(f'{fact(5)}')

# sum=lambda arg1,arg2:arg1+arg2
# print(sum(10,20))
# print(sum(20,20))

# i=0
# while i<8:
#     print(f'{i}<8')
#     i+=1

# a=int(input())
# i=1
# sum=0
# while i<=a:
#     sum+=i
#     i+=1
# print(sum)

# i=0
# while i<3:
#     j=0
#     while j<3:
#         print(f'循环{i*3+j+1}次')
#         j+=1
#     i+=1

# func=lambda x:x+2
# restult=map(func,[1,2,3,4,5])
# print(restult)
# print(list(restult))

# for循环 for 临时变量 in 可迭代对象：
#                循环体
# str='hellopython'
# for i in str:
#     print(i)

# range 记录循环次数
# for i in range(1,6): # 包前不包后
#     print(i)

# from functools import reduce
# func=lambda x,y:x+y
# restult=reduce(func,[1,2,3,4,5])
# print(restult)

a=int(input())
sum=0
for i in range(a+1):
    sum+=i
    if sum>3000:
        break
print(sum)