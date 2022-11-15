import pandas as pd
import numpy as np
from sklearn import preprocessing, linear_model
from sklearn.linear_model import LinearRegression
from sklearn.feature_selection import f_regression

NBApoints_data= pd.read_csv("NBApoints.csv")
NBApoints_data.info()
NBApoints_data.describe()


label_encoder_conver = preprocessing.LabelEncoder()
Pos_encoder_value = label_encoder_conver.fit_transform(NBApoints_data["Pos"])
print(Pos_encoder_value)
print("\n")

label_encoder_conver = preprocessing.LabelEncoder()
Tm_encoder_value = label_encoder_conver.fit_transform(NBApoints_data["Tm"])
print(Tm_encoder_value)

train_X = pd.DataFrame([Pos_encoder_value,NBApoints_data["Age"],Tm_encoder_value]).T
                        
#train_X = pd.DataFrame([Pos_encoder_value,NBApoints_data["Age"]]).T

NBApoints_linear_model = LinearRegression()
NBApoints_linear_model.fit(train_X, NBApoints_data["3P"])

NBApoints_linear_model_predict_result= NBApoints_linear_model.predict([[5,28,10]])
print('三分球得球數=',"% .4f" % NBApoints_linear_model_predict_result)

r_squared = NBApoints_linear_model.score(train_X, NBApoints_data["3P"])
print('R_squared值=',"% .4f" % r_squared)

print("f_regresstion\n")
print("P值=",f_regression(train_X, NBApoints_data["3P"])[1])
print("\n")
