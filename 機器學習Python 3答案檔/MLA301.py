import pandas as pd
import numpy as np
from sklearn.datasets import load_iris
iris_dataset = load_iris()

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(
    iris_dataset['data'], iris_dataset['target'],test_size=0.4, random_state=1)
k = 3
# create dataframe from data in X_train 根據X_train中的資料創建dataframe
# label the columns using the strings in iris_dataset.feature_names 使用iris_dataset.feature_names中的字串標記列
iris_dataframe = pd.DataFrame(X_train, columns=iris_dataset.feature_names)

from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(n_neighbors=k)
knn.fit(X_train, y_train)

print("Test set score: {:.4f}".format(knn.score(X_test, y_test)))
X_new1 = np.array([[5, 2.9, 1, 0.2]])
prediction1 = knn.predict(X_new1)
print("Predicted target name:",iris_dataset['target_names'][prediction1])

X_new2 = np.array([[5.7, 2.8, 4.5, 1.2]])
prediction2 = knn.predict(X_new2)
print("Predicted target name:",iris_dataset['target_names'][prediction2])

X_new3 = np.array([[7.7, 3.8, 6.7, 2.1]])
prediction3 = knn.predict(X_new3)
print("Predicted target name:",iris_dataset['target_names'][prediction3])
