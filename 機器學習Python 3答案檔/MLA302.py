#from sklearn import datasets
#from sklearn.model_selection import cross_val_predict
#from sklearn import linear_model
import pandas as pd
import numpy as np
from sklearn.datasets import load_boston
boston = load_boston()
df = pd.DataFrame(boston.data.T, ['CRIM','ZN','INDUS','CHAS','NOX','RM' ,'AGE','DIS','RAD','TAX', 'PTRATIO','B','LSTAT']) #有13個feature
df = df.T
df['MEDV'] = boston.target.T  # MEDV即預測目標向量
from sklearn.model_selection import train_test_split
X = df[['CRIM','ZN','INDUS','CHAS','NOX','RM' ,'AGE','DIS','RAD','TAX', 'PTRATIO','B','LSTAT']]
y = df['MEDV']

#分出20%的資料作為test set
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2,random_state=1)

from sklearn.linear_model import LinearRegression
lm = LinearRegression()
lm.fit(X_train,y_train) #Fit linear model 配適線性模型
predictions = lm.predict(X_test)

from sklearn import metrics
print('MAE:', "%.4f" % metrics.mean_absolute_error(y_test, predictions))
print('MSE:', "%.4f" % metrics.mean_squared_error(y_test, predictions))
print('RMSE:', "%.4f" % np.sqrt(metrics.mean_squared_error(y_test, predictions)))

X_new = np.array([[0.00632, 18.00, 2.310, 0, 0.5380, 6.5750, 65.20, 4.0900, 1, 296.0, 15.30, 396.90, 4.98]])
prediction = lm.predict(X_new)
print("%.4f" % prediction)
