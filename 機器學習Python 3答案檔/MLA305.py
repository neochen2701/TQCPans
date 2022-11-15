# #############################################################################
# 本題參數設定，請勿更改
seed = 0   # 亂數種子數  
# #############################################################################
import warnings
warnings.filterwarnings('ignore')

import numpy as np
import pandas as pd 

evaluation = pd.DataFrame({'Model': [],
                           'Details':[],
                           'RMSE (test)':[],
                           'R2 (train)':[],
                           'adj. R2 (train)':[],
                           'R2 (test)':[],
                           'adj. R2 (test)':[]}
                            )

# 讀取台北市房價資料集
df = pd.read_csv('Taipei_house.csv')

# 對"行政區"進行 one-hot encoding
df = pd.get_dummies(df, columns=['行政區'])
# 處理"車位類別"
df['車位類別'] = [0 if x=='無' else 1 for x in df['車位類別']]

# 計算 Adjusted R-squared
def adj_R2(r2, n, k):
    """ 函式描述：計算 Adjusted R-squared
    參數：
        r2:R-squared 數值
        n: 樣本數
        k: 特徵數

    回傳：
        Adjusted R-squared
    """
    return r2-(k-1)/(n-k)*(1-r2)

from sklearn.metrics import mean_squared_error
def measurement(model, X_train, X_test):
    y_pred = model.predict(X_test)
    
    rmse = round(np.sqrt(mean_squared_error(y_test, y_pred)), 0)
    r2_train = round(model.score(X_train, y_train), 4)
    adj_r2_train = round(adj_R2(model.score(X_train, y_train), 
                                X_train.shape[0], X_train.shape[1]), 4)
    r2_test = round(model.score(X_test, y_test), 4)
    adj_r2_test = round(adj_R2(model.score(X_test, y_test), 
                               X_test.shape[0], X_test.shape[1]), 4)
    return [rmse, r2_train, adj_r2_train, r2_test, adj_r2_test]

# 切分訓練集(80%)、測試集(20%)
features= ['土地面積', '建物總面積', '屋齡', '樓層', '總樓層', '用途', 
           '房數', '廳數', '衛數', '電梯', '車位類別', 
           '行政區_信義區', '行政區_大安區', '行政區_文山區','行政區_松山區']
target = '總價'    
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(df[features],
                                                    df[target],
                                                    test_size=0.2, 
                                                    random_state=seed)

lst_model, lst_info = [], []
# 複迴歸(參數皆為預設值)
# #########################################################################
# '行政區_信義區', '行政區_大安區', '行政區_文山區','行政區_松山區' 四個特徵是經過
# one-hot encoding 後產生，若欄位名稱不同可自行修改之。
# #########################################################################
from sklearn import linear_model
lst_model.append(linear_model.LinearRegression())
lst_info.append(['複迴歸','15 features'])

# 脊迴歸(Ridge regression)，除以下參數設定外，其餘為預設值
# #########################################################################
# alpha=10
# #########################################################################
lst_model.append(linear_model.Ridge(alpha=10))
lst_info.append(['Ridge','15 features'])

# 多項式迴歸，除以下參數設定外，其餘為預設值
# #########################################################################
# degree=2
# #########################################################################
from sklearn.preprocessing import PolynomialFeatures
poly_fea = PolynomialFeatures(degree=2)
X_train_poly = poly_fea.fit_transform(X_train)
X_test_poly = poly_fea.fit_transform(X_test)

lst_model.append(linear_model.LinearRegression())
lst_info.append(['多項式迴歸','deg=2'])

# 多項式迴歸 + Lasso迴歸，除以下參數設定外，其餘為預設值
# #########################################################################
# alpha=10
# #########################################################################
lst_model.append(linear_model.Lasso(alpha=10))
lst_info.append(['多項式迴歸+Lasso','deg=2'])

idx = evaluation.shape[0]
for i in range(len(lst_model)):
    if '多項式' in lst_info[i][0]:
        X_train, X_test = X_train_poly, X_test_poly
    
    model = lst_model[i].fit(X_train, y_train)
    row = lst_info[i] + measurement(model, X_train, X_test)
    evaluation.loc[idx+i] = row

print('對訓練集的最大 Adjusted R-squared: %.4f' % max(evaluation['adj. R2 (train)']))
print('對測試集的最小 RMSE:%d' % min(evaluation['RMSE (test)']))
print('兩個模型對測試集的最大 Adjusted R-squared: %.4f' % 
      max(evaluation.loc[:1, 'adj. R2 (test)']))

''' 預測 '''
# 利用所有資料重新擬合模型，並進行預測
X = df[features]
y = df[target]
X_poly = poly_fea.fit_transform(X)

#features= ['土地面積', '建物總面積', '屋齡', '樓層', '總樓層', '用途', 
#           '房數', '廳數', '衛數', '電梯', '車位類別', 
#           '行政區_信義區', '行政區_大安區', '行政區_文山區','行政區_松山區']
new = np.array([36, 99, 32, 4, 4, 0, 3, 2, 1, 0, 0, 0, 0, 0, 1]).reshape(1, -1)
df_new = pd.DataFrame(new, columns=features)
df_poly_fea = poly_fea.fit_transform(df_new)

lst = evaluation['adj. R2 (test)'].tolist()
idx = lst.index(max(lst))
if idx <=1:
    model = lst_model[idx].fit(X, y)
    print('房價預測結果：%d' % model.predict(df_new))
else:
    model = lst_model[idx].fit(X_poly, y)
    print('房價預測結果：%d' % model.predict(df_poly_fea))




