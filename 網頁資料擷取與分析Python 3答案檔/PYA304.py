# 載入 numpy 模組縮寫為 np
import numpy as np
# 載入 pandas 模組縮寫為 pd
import pandas as pd

# 使用 pd 的 read_csv 方法讀入 read.csv 檔案
df = pd.read_csv("read.csv")
# 將 df 中的 data 欄位取出為 ndarray
data = df["data"].values

# 使用 type 函數判斷資料型態
print('資料型態：%s' % type(data))
# 使用 np.mean() 函數計算平均數
print('平均值：%.2f' % np.mean(data))
# 使用 np.median() 函數計算中位數
print('中位數：%.2f' % np.median(data))
# 使用 np.std() 函數計算標準差
print('標準差：%.2f' % np.std(data))
# 使用 np.var() 函數計算變異數
print('變異數：%.2f' % np.var(data))
# 使用 np.ptp() 函數計算極差值
print('極差值：%.2f' % np.ptp(data))
