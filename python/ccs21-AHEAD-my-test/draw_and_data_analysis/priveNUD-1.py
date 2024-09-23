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




x_axis_data = [0, 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]  # x
y_axis_data1 = [0.000035745301866244, 0.0000320443049591418, 0.0000321925286237873, 0.0000337200247040594, 0.000027781868686709,
                0.0000257780983264349, 0.0000287532127081954, 0.00002645890786758, 0.00002945705978444, 0.00003498795423568]  # y

y_axis_data2 = [0.000035745301866244, 0.0000244049095058047, 0.0000270376248955074, 0.0000268775770885679, 0.0000275636089709623, 0.00002840373986433,
                0.000027230355986, 0.0000243306765, 0.0000256488945232, 0.000024816657693716]
y_axis_data3 = [0.000035745301866244, 0.0000403148040131134,0.000153512016049678, 0.000145271055832701, 0.000136970803728973, 0.000117042676624137,
                0.000115806386952561, 0.000120416791715976, 0.000122886418652943, 0.000128202794987724]

plt.plot(x_axis_data, y_axis_data1, 'rs--', alpha=0.5, linewidth=2.5, label='RPA')  # 'bo-'表示蓝色实线，数据点实心原点标注
## plot中参数的含义分别是横轴值，纵轴值，线的形状（'s'方块,'o'实心圆点，'*'五角星   ...，颜色，透明度,线的宽度和标签 ，

plt.plot(x_axis_data, y_axis_data2, 'yo--', alpha=0.5, linewidth=2.5,markerfacecolor='none', markeredgecolor='y', label='RIA')

plt.plot(x_axis_data, y_axis_data3, 'b*--', alpha=0.5, linewidth=2.5, label='OPA')


plt.legend()  # 显示上面的label
plt.xlabel('假用户m', fontsize=19, fontname='SimSun')  # x_label
plt.ylabel('均值方差MSE', fontsize=19, fontname='SimSun')  # y_label

# plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
