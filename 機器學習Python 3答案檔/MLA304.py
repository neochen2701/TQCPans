from sklearn import datasets
import pandas as pd
from sklearn.linear_model import LinearRegression
import numpy as np
from sklearn.model_selection import train_test_split
diabetes=datasets.load_diabetes()
#get x
x=pd.DataFrame(diabetes.data, columns=diabetes.feature_names)
target=pd.DataFrame(diabetes.target, columns=["MEDV"])
y=target["MEDV"]
#Total number of examples
lm1=LinearRegression()
lm1.fit(x, y)
pred1=lm1.predict(x)
MSE1=np.mean((pred1-y)**2)
print('Total number of examples')
print('MSE=', "%.4f" %MSE1)
print('R-squared=', "%.4f" %lm1.score(x, y))
#3:1 100
xTrain2, xTest2, yTrain2, yTest2=train_test_split(x, y, test_size=0.25, random_state=100)
lm2=LinearRegression()
lm2.fit(xTrain2, yTrain2)
pred2_train=lm2.predict(xTrain2)
MSE2_train=np.mean((yTrain2-pred2_train)**2)
pred2_test=lm2.predict(xTest2)
MSE2_test=np.mean((yTest2-pred2_test)**2)
print('Split 3:1')
print('train MSE=', "%.4f" % MSE2_train)
print('test MSE=', "%.4f" % MSE2_test)
print('train R-squared=', "%.4f" % lm2.score(xTrain2, yTrain2))
print('test R-squared=', "%.4f" % lm2.score(xTest2, yTest2))
