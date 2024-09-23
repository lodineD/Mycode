import matplotlib.pyplot as plt
import numpy as np

# 设置中文字体为宋体
plt.rcParams['font.sans-serif'] = ['SimSun']  # 宋体的常见名称
plt.rcParams['axes.unicode_minus'] = False  # 正确显示负号


# 柱状图中的 x 轴位置
ind = np.arange(5)  # 为4个柱子设置4个位置

# 各柱子的高度
width = 0.5  # 柱子的宽度
bar_heights = [8758, 3632, 982, 940, 523]

# 创建一个图形和坐标轴对象
fig, ax = plt.subplots()

# 或者使用RGB颜色代码设置为浅蓝色
ax.bar(ind, bar_heights, width, color=(0.68, 0.85, 0.90))

# 添加水平参考线
ax.axhline(2000, color='gray', linestyle='--', linewidth=1)
ax.axhline(4000, color='gray', linestyle='--', linewidth=1)
ax.axhline(6000, color='gray', linestyle='--', linewidth=1)
ax.axhline(8000, color='gray', linestyle='--', linewidth=1)


# # 添加条形图中的文本
# for i in ind:
#     plt.text(i, bar_heights[i]/2, str(bar_heights[i]), ha='center', va='bottom')

# 设置 x 轴的刻度标签
plt.xticks(ind, ('金融', '物流', '航旅', '电商', '汽车'))

# 添加标题等装饰
# plt.title('Example Bar Chart')
# plt.xlabel('泄露事件数')
plt.ylabel('泄露事件数')

# 显示图表
plt.show()