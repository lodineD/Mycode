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
y_axis_data1 = [0.00056656, 0.00035745301866244, 0.000369768954784632, 0.000421423717862515, 0.000215664961639197,
    0.000486254680564435, 0.000231612437486589, 0.00072667212396365, 0.000579546377763353, 0.000273496938293819]  # y

y_axis_data2 = [0.00056656, 0.000423392842378112, 0.000194118340874816, 0.000250429795991146, 0.000276143481039036, 0.000831408463974342,
                0.00021115234386387, 0.000612012697516872, 0.00114781894046333, 0.000358925715912956]
y_axis_data3 = [0.00056656, 0.00558782914293725, 0.00811121939312886, 0.00965711129803197, 0.00957643516354309, 0.010994736309933,
                0.0104343470560457, 0.00954449463031714, 0.0104510453966373, 0.00930824050927105]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')

plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
