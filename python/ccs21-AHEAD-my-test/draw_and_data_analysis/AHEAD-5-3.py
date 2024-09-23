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
y_axis_data1 = [0.00038359319338436,0.00035029519039668, 0.00074983050001476, 0.00035618175262466, 0.00042190741155618,
    0.0005764933195453, 0.00039420252375189, 0.00056304406216361, 0.00063341572730474, 0.00065554702694661]  # y

y_axis_data2 = [0.00038359319338436,0.00064332347783979, 0.0007961976325237, 0.00066391584507451, 0.00053346907048912, 0.00063520115980291, 0.00051526632425774,
                0.00069983551840389, 0.0003611406176789, 0.00077619443107174]
y_axis_data3 = [0.00038359319338436, 0.00459829458141788, 0.00850429744069662, 0.00932751132552753, 0.00943922602499384, 0.00860052346729602,
                0.00903992043086376, 0.00930525212834471, 0.00889828580940879, 0.0086707228553277]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')


plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
