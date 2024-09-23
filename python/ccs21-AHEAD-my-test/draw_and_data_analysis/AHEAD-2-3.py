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


y_axis_data1 = [0.00055186429381418,0.00087188771959725, 0.00104273558855724, 0.00071731139093027, 0.00044253096519847,
    0.00083318281509754, 0.00079968260145059, 0.00084700460641387, 0.00128310319841731, 0.00063453070199105]  # y

y_axis_data2 = [0.00055186429381418, 0.0013996509854702, 0.00128023548827294, 0.00099442092972794, 0.00138979038455632, 0.00099586717243108, 0.0013986669293695,
                0.00066902317352015, 0.00128087659162603, 0.00077893541063384]
y_axis_data3 = [0.00055186429381418, 0.0047664736626105, 0.00824430258751052, 0.00810149968983181, 0.0073170644209523, 0.00756783615477558,
                0.00845773358579329, 0.00867966400045508, 0.00834819961279845, 0.00856646677787349]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')


plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
