import pandas as pd
import numpy as np
from sklearn import preprocessing, linear_model

# 原始資料
titanic = pd.read_csv("titanic.csv")
print('raw data')
titanic.info()

# 將年齡的空值填入年齡的中位數
age_median = np.nanmedian(titanic["Age"])
print()
print("年齡中位數=", age_median)
print()
new_age = np.where(titanic["Age"].isnull(), age_median, titanic["Age"])
titanic["Age"] = new_age

# 更新後資料
print('new data')
titanic.info()
print()

# 轉換欄位值成為數值
label_encoder = preprocessing.LabelEncoder()
encoded_class = label_encoder.fit_transform(titanic["PClass"])

X = pd.DataFrame([encoded_class, titanic["SexCode"], titanic["Age"]]).T
y = titanic["Survived"]

# 建立模型
logistic = linear_model.LogisticRegression()
logistic.fit(X, y)
print('截距=',logistic.intercept_ )
print('迴歸係數=',logistic.coef_)


# 混淆矩陣(Confusion Matrix)，計算準確度
print('Confusion Matrix')
preds = logistic.predict(X)
print(pd.crosstab(preds, titanic["Survived"]))
print(logistic.score(X, y))


