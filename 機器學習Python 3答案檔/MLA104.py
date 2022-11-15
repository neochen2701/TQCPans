import pandas as pd

# 載入寶可夢資料集
df = pd.read_csv('pokemon.csv')

# 處理遺漏值
features = ['Attack', 'Defense']
df.dropna(axis=0, subset=features, inplace=True)

# 取出目標寶可夢的 Type1 與兩個特徵欄位
df_data = df[(df['Type1']=='Ghost') | (df['Type1']=='Normal') \
             | (df['Type1']=='Fighting')]
X_train, y_train = df_data[features], df_data['Type1']

# 編碼 Type1
from sklearn.preprocessing import LabelEncoder
le = LabelEncoder()
y_train = le.fit_transform(y_train)

# 特徵標準化
from sklearn.preprocessing import StandardScaler
scalar = StandardScaler()
scalar.fit(X_train)
X_train_std = scalar.transform(X_train)

# 建立線性支援向量分類器，除以下參數設定外，其餘為預設值
# #############################################################################
# C=0.1, dual=False, class_weight='balanced'
# #############################################################################
from sklearn.svm import LinearSVC
model = LinearSVC(C=0.1, dual=False, class_weight='balanced')
model.fit(X_train_std, y_train)

# 計算分類錯誤的數量
y_pred = model.predict(X_train_std)
print('Misclassified samples: %d' % (y_train != y_pred).sum())

# 計算準確度(accuracy)
from sklearn.metrics import accuracy_score
print('Accuracy: %.4f' % accuracy_score(y_train, y_pred))

# 計算有加權的 F1-score (weighted)
from sklearn.metrics import f1_score
f1 = f1_score(y_train, y_pred, average='weighted')
print('F1-score: %.4f' % f1)

# 預測未知寶可夢的 Type1
new_data = [[100, 75]]
new_data = scalar.transform(new_data)
label = le.inverse_transform(model.predict(new_data))
print(label)


