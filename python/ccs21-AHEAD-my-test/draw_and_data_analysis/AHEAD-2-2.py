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


# 设置纵轴的刻度，以0.002为一个刻度
plt.yticks(np.arange(0.002, 0.0081, 0.002), ['0.002', '0.004', '0.006', '0.008'])


x_axis_data = [0, 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]  # x
y_axis_data1 = [0.00088021070978285, 0.000678943561, 0.0009875631, 0.0015945681, 0.0008945681,0.00125786132, 0.00085786132, 0.000894891232, 0.0011894532, 0.0008278651]  # y

y_axis_data2 = [0.00088021070978285, 0.00078456132564, 0.00127865412, 0.00097865412, 0.001045632198791, 0.0013132967981, 0.000979869832, 0.000818945613, 0.000897894561, 0.0010246552]
y_axis_data3 = [0.00088021070978285, 0.00487894561, 0.00825648923, 0.0070654321987, 0.0080786132,
                0.007279863, 0.00757894532, 0.008278945613, 0.0085789461513, 0.0083456137956]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')


plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
