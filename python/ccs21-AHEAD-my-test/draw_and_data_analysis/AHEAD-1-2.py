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
plt.axhline(y=0.010, linestyle='--', color='gray')
plt.axhline(y=0.012, linestyle='--', color='gray')

# # 添加一条竖直虚线
# plt.axvline(x=1000, linestyle='--', color='gray')
# plt.axvline(x=2000, linestyle='--', color='gray')
# plt.axvline(x=3000, linestyle='--', color='gray')
# plt.axvline(x=4000, linestyle='--', color='gray')
# plt.axvline(x=5000, linestyle='--', color='gray')
# plt.axvline(x=6000, linestyle='--', color='gray')
# plt.axvline(x=7000, linestyle='--', color='gray')
# plt.axvline(x=8000, linestyle='--', color='gray')


x_axis_data = [0, 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]  # x
y_axis_data1 = [0.0002798465156246, 0.0002987564123, 0.000388789454565, 0.000345689456132, 0.00028875641324, 0.000306542138946512,
                0.000405451265, 0.00035789465123, 0.0003689132545, 0.000297894651]

y_axis_data2 = [0.0002798465156246, 0.00068426313854712, 0.0006952482982633, 0.00079836528072428, 0.00094389167201959,
    0.00049704287266024, 0.00056686336476011, 0.00082875740323444, 0.00057705979816545, 0.00082872157135156]  # y


y_axis_data3 = [0.0002798465156246, 0.00578564321, 0.009786541, 0.010798456132, 0.01229654187, 0.010789456132,
                0.011498739871132, 0.012789556132, 0.01178953546123, 0.01178953546123]



plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')








plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
