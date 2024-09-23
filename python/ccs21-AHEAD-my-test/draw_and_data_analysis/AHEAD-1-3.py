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
y_axis_data1 = [0.00060173774489862, 0.00057856682414225, 0.00078120988929396, 0.00053016564779225, 0.00081306018059234,
    0.00070758762953944, 0.00047332699880495, 0.00085077598409193, 0.00091851602338887, 0.00047850417886354]  # y

y_axis_data2 = [0.00063273268294323, 0.00095976313306825, 0.00044285010809928, 0.00041476911272518, 0.00082808926930314, 0.00070577478639788,
                0.00047184035577903, 0.000612012697516872, 0.00051667115596477, 0.00088773543247598]
y_axis_data3 = [0.00060173774489862, 0.005098136741698456, 0.00880229552260708, 0.0091958378138655, 0.00998330709028533, 0.011740516454366,
                0.0104384004845743, 0.00962148195907211, 0.00980714137220868, 0.0112688020550517]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')








plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
