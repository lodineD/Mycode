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
y_axis_data2 = [0.0007465132,0.0006234321546, 0.0011849813, 0.00054784653, 0.0003878949611,
    0.00127894841321, 0.00055798981613, 0.0005978946513, 0.0013879846513, 0.00069798456132]  # y

y_axis_data1 = [0.0007465132,0.000847984651, 0.00058798432, 0.000797894328, 0.00050798413297, 0.00032987116513256, 0.0002978974651321,
                0.00033789545612, 0.00066898613256566, 0.000727984561]
y_axis_data3 = [0.0007465132, 0.0052798613235, 0.0085798431579, 0.0081987613148, 0.009679846513, 0.0090979843154,
                0.009398756132, 0.008879865132598, 0.0084941613256, 0.00857984651321]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')


plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
