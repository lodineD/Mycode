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
y_axis_data1 = [0.00091183903473167,0.000896454110097881, 0.000449894840687785, 0.0010030211038733, 0.00126368752132194,
    0.00166025792752644, 0.000475101707664284, 0.000853104503794032, 0.00050584959510486, 0.000892939542922206]  # y

y_axis_data2 = [0.00091183903473167, 0.000776546894082953, 0.000715605416477003, 0.000549435433295539, 0.000702730850823816, 0.000950770246638469, 0.00111760854709165,
                0.000671458777200955, 0.00146381036208394, 0.000968584474219746]
y_axis_data3 = [0.00091183903473167, 0.00409421124684305, 0.00867211053638415, 0.00692502523051117, 0.00811773655387285, 0.00720328643101938,
                0.00734412134319638, 0.00681451752289283, 0.00782821292721502, 0.00861666957352963]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')


plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
