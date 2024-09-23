import numpy as np

# 设置5组正态分布的参数：均值（mean）和标准差（std）
means = [250, 350, 450, 550, 650]  # 5组数据的均值
stds = [50, 50, 50, 50, 50]        # 5组数据的标准差

# 生成10万个服从正态分布的浮点数数据，每组10万个数据点
data = [np.random.normal(mean, std, 100000) for mean, std in zip(means, stds)]

# 打开一个文件用于写入数据
with open('five_groups_normal_data.txt', 'w') as file:
    # 将5组数据交替写入文件，每行5个数
    for tuples in zip(*data):  # 使用zip(*)来打包每组的对应元素
        # 将每组数据格式化为字符串，写入到文件中，每行5个数
        line = ' '.join(f"{value:.0f}" for value in tuples)
        file.write(line + '\n')