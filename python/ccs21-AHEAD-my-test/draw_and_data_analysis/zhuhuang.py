import matplotlib.pyplot as plt
import numpy as np

# 设置中文字体为宋体
plt.rcParams['font.sans-serif'] = ['SimSun']  # 宋体的常见名称
plt.rcParams['axes.unicode_minus'] = False  # 正确显示负号


# 柱状图中的 x 轴位置
ind = np.arange(5)  # 为4个柱子设置4个位置

# 各柱子的高度
width = 0.5  # 柱子的宽度
bar_heights = [94.57, 87.58, 91.99, 72.12, 81.54]

# 创建一个图形和坐标轴对象
fig, ax = plt.subplots()

# 创建条形图
ax.bar(ind, bar_heights, width, color='gray')  # 将柱子设置为灰色

# 添加水平参考线
ax.axhline(80, color='gray', linestyle='--', linewidth=1)
ax.axhline(60, color='gray', linestyle='--', linewidth=1)
ax.axhline(40, color='gray', linestyle='--', linewidth=1)
ax.axhline(20, color='gray', linestyle='--', linewidth=1)


# # 添加条形图中的文本
# for i in ind:
#     plt.text(i, bar_heights[i]/2, str(bar_heights[i]), ha='center', va='bottom')

# 设置 x 轴的刻度标签
plt.xticks(ind, ('AHEAD-1', 'priveNUD-1', 'AHEAD-2', 'AHEAD-5', 'priveNUD-5'))

# 添加标题等装饰
# plt.title('Example Bar Chart')
plt.xlabel('不同维度的各协议')
plt.ylabel('相对百分比%')

# 显示图表
plt.show()