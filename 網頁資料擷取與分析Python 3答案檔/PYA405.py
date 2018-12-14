# --開始--批改評分使用，請勿變動
import matplotlib as mpl
mpl.use('Agg')
set_seed = 123
# --結束--批改評分使用，請勿變動

# 載入 numpy 模組並縮寫為 np
import numpy as np
# 載入 matplotlib.pyplot 並縮寫為 plt
import matplotlib.pyplot as plt

samples_1 = np.random.RandomState(set_seed).normal(loc=1, scale=.5, size=1000)
samples_2 = np.random.RandomState(set_seed).standard_t(df=10, size=1000)
bins = np.linspace(-3, 3, 100)

# 第一個子圖
plt.subplot(2, 2, 1)
plt.hist(samples_1, bins=bins, alpha=0.5, label='samples 1')
plt.hist(samples_2, bins=bins, alpha=0.5, label='samples 2')
# 在左上角 upper left 放置圖例 legend
plt.legend(loc='upper left')

# 第二個子圖
plt.subplot(1, 2, 2)
plt.scatter(samples_1, samples_2, alpha=0.2)

plt.savefig('chart.png')
plt.close()
