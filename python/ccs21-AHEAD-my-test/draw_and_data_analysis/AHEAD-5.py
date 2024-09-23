import matplotlib.pyplot as plt
import numpy as np


# 设置中文字体为宋体
plt.rcParams['font.sans-serif'] = ['SimSun']  # 宋体的常见名称
plt.rcParams['axes.unicode_minus'] = False  # 正确显示负号

# 添加一条水平虚线
plt.axhline(y=0.002, linestyle='--', color='gray')
plt.axhline(y=0.004, linestyle='--', color='gray')
plt.axhline(y=0.006, linestyle='--', color='gray')
plt.axhline(y=0.008, linestyle='--', color='gray')


x_axis_data = [0, 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]  # x
y_axis_data1 = [0.000722467441633006,0.000335856263671446, 0.000479771784389316, 0.0007825592913186, 0.000678117499187555,
    0.000542393477280442, 0.000549894856336175, 0.000469094501793581, 0.000329232890913248, 0.000540612164882398]  # y

y_axis_data2 = [0.000722467441633006,0.000612407167885981, 0.000702561675028084, 0.000339342742053523, 0.000593869072245974, 0.00034784899095844, 0.00045843732681962,
                0.000558525228549635, 0.000504038247422725, 0.000630281062681769]
y_axis_data3 = [0.000722467441633006, 0.00483270463521754, 0.00920901388767115, 0.00913552258516904, 0.00893025524929399, 0.00936237807174661,
                0.00920538761972529, 0.00890363907441197, 0.0092005019851136, 0.00902478916014008]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')


plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
