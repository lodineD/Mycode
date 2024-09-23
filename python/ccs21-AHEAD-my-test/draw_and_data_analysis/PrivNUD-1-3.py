import matplotlib.pyplot as plt
import numpy as np


# 设置中文字体为宋体
plt.rcParams['font.sans-serif'] = ['SimSun']  # 宋体的常见名称
plt.rcParams['axes.unicode_minus'] = False  # 正确显示负号

# 添加一条水平虚线
plt.axhline(y=0.00004, linestyle='--', color='gray')
plt.axhline(y=0.00006, linestyle='--', color='gray')
plt.axhline(y=0.00008, linestyle='--', color='gray')
plt.axhline(y=0.00010, linestyle='--', color='gray')
plt.axhline(y=0.00012, linestyle='--', color='gray')
plt.axhline(y=0.00014, linestyle='--', color='gray')
plt.axhline(y=0.00016, linestyle='--', color='gray')




x_axis_data = [0, 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]  # x
y_axis_data1 = [0.0000351033298413, 0.00002767457837729, 0.00002572218350637, 0.00003279091817416,0.00003175683761304,0.00002949385603375, 0.00002861073947557,
                0.00003008284277495, 0.00002192282897261, 0.00003049501565008]  # y

y_axis_data2 = [0.0000351033298413, 0.00003529517458239, 0.00002290651513356, 0.00002821289347538, 0.00002509225451148, 0.00002310687686782,
                0.00002726072402876, 0.00003615981544703, 0.00003016559396707, 0.00002893699470368]
y_axis_data3 = [0.0000351033298413, 0.0000479308195474, 0.00016759460332193,0.00015161671188488, 0.00014800003358943, 0.00012141517461788, 0.00012950768817066,
                0.00015161671188488, 0.00014745828736724, 0.00014042781034468]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')


plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
