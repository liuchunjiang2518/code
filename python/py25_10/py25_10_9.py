import pytest
import pygame
import random
import time
# 异常
# raise Exception('ERROR')
def funa():
    raise Exception('你错了')
    print('haha') # 不会执行
funa()
def funa():
    password=input('请输入密码')
    if(len(password)>=6):
        print('密码输入成功')
        return password
    raise Exception ('密码应大于六位')
try:
    funa()
except Exception as e:
    print(e)

# 模块 一个py文件就是一个模块
# 内置模块
# random time os logging
# 第三方模块
# 下载 cmd中 pip install 模块名
# 自定义模块 尽量不要与内置模块其冲突

# 导入模块
# 模块名加功能名
# pytest.funa()
# print(pytest.name)
# from pytest import funb,name
# funb()
# print(name)
# from pytest import * # *代表所有
# import pytest as pt
# pt.funa()
# from pytest import funa as a,funb as b
# a()
# 内置全局变量
# if __name__ =='__main__':
# 用来控制python文件在不同场景执行不同逻辑
# import pytest
# import pytest2
# pytest2.test()
# print(pytest2.test2(3))

# 包
# 将有联系的模块放入同一个文件夹，并加入__init__.py
import pack25_10_9
pack25_10_9.register.reg()  