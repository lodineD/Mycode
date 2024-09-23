import matplotlib.pyplot as plt
import numpy as np


# 设置中文字体为宋体
plt.rcParams['font.sans-serif'] = ['SimSun']  # 宋体的常见名称
plt.rcParams['axes.unicode_minus'] = False  # 正确显示负号

# 添加一条水平虚线
plt.axhline(y=0.00002, linestyle='--', color='gray')
plt.axhline(y=0.00004, linestyle='--', color='gray')
plt.axhline(y=0.00006, linestyle='--', color='gray')
plt.axhline(y=0.00008, linestyle='--', color='gray')
plt.axhline(y=0.00010, linestyle='--', color='gray')





x_axis_data = [0, 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]  # x
y_axis_data1 = [0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338,
                0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338]  # y

y_axis_data2 = [0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338,
                0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338, 0.0000191068365010338]
y_axis_data3 = [0.0000191068365010338, 0.000103535580552321,0.000103535580552321,0.000103535580552321, 0.000103535580552321, 0.000103535580552321,
                0.000103535580552321, 0.000103535580552321, 0.000103535580552321, 0.000103535580552321]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')


plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
