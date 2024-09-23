import treelib
import numpy as np
import math
from treelib import Tree, Node
import pandas as pd
import os
from func_module import freqoracle
from func_module import errormetric
from func_module import realfreq
import random
from random import choice

# 老的数据集是一共100000个值
data_path_old = './dataset/5dim_laplace08-set_10_6-domain6_attribute5-data.txt'
data_path_new = './dataset/5dim_laplace08-set_10_6-domain6_attribute5-data.txt'

# 数据长度
def know_data_len(data_path_old):
    f = open(data_path_old)
    data_old = []
    for line in f:
        data_old.append(line.strip())
    f.close()
    return len(data_old)

# 输入数据
def input_data(data_path_new, new_data):
    f = open(data_path_new, "a")

    for line in new_data:
        f.write(str(line)+'\n')
    f.close()

# 输出数据
def output_data(data_path):
    f = open(data_path)
    data = []
    for line in f:
        data.append(line.strip())
    f.close()
    print(data)

# 这个函数用来看看数据集的最大和最小值，以及它们的位置，便于分组
def check_data(data_path):
    f = open(data_path)
    data_old = []
    for line in f:
        data_old.append(line.strip())
    f.close()
    # print(data_old)

    list_length = len(data_old)
    print(list_length)
    return list_length

# 该函数用于删除进入的污染数据
# def clear(person):
#     f = open(data_path_old)
#     data_old = []
#     for line in f:
#         data_old.append(line.strip())
#     del_line = len(data_old)
#     f.close()
#
#     f.open(data_path_new)
#     current_line = 0
#     # 到达要删除的行
#     while current_line < del_line:
#         f.readline()
#         current_line += 1
#     seek_point = f.tell()
#     f.seek(seek_point, 0)
#


# 所有假用户从用户域中随机选择一个值，进行复制，再攻击，假用户和假值为多对一关系，person值为假用户数
def attack_origin(person):
    f = open(data_path_old)
    data_old = []
    for line in f:
        data_old.append(line.strip())
    f.close()
    num = choice(data_old)
    f = open(data_path_new, "a")
    for m in range(person):
        f.write(str(num)+'\n')
    f.close()
    print("origin攻击成功，已经注入"+str(person)+"个假用户,"+"数值为"+str(num))


# 每一个假用户随机选择一个值攻击，假用户和假值为一对一关系，person值为假用户数
def attack_RPA(person):
    f = open(data_path_old)
    data_old = []
    for line in f:
        data_old.append(line.strip())
    f.close()
    f = open(data_path_new, "a")
    for m in range(person):
        num = choice(data_old)
        f.write(str(num)+'\n')
    f.close()
    print("RPA攻击成功，已经注入"+str(person)+"个假用户")


# 将用户域分组，并重复和攻击一组的数据，person为假用户值，分组的条件和思想可以自己看着办，可以研究什么时候是最有效的
def attack_RIA(person):
    f = open(data_path_old)
    data_old = []
    for line in f:
        data_old.append(line.strip())
    f.close()

    # 总步长
    long = check_data(data_path_old)
    # 组数
    group_num = 4

    # print(long)
    # 随机选择组
    group_index = random.randint(1, 4)
    # print(group_index)

    # 步长
    turn_line = int(long / group_num)
    # print(data_old)
    print(turn_line)
    f = open(data_path_new, "a")
    for m in range(person):
        left = int(turn_line * (group_index - 1))
        print(left)
        random_user = random.choice(data_old[left:left+turn_line])
        print("第" + str(m+1) + "次随机数为" + str(random_user))
        f.write(str(random_user) + '\n')
    f.close()
    print("RIA攻击成功，已经注入"+str(person)+"个假用户,选择的是第"+str(group_index)+"组")

# m = 200
# attack_origin(m)


# m = 6000
# attack_RIA(m)

# check_data(data_path_old)


# 假用户的数量
m = 1000
attack_RPA(m)

# length_old = know_data_len(data_path_old)
# print(length_old)
# list_1 =[1, 2, 3, 4, 5]
# input_data(data_path_new, list_1)
# output_data(data_path_new)
