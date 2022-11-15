import numpy as np

input_file = 'wine.csv'

X = []
y = []
with open(input_file) as f:
    for line in f.readlines():
        data = [float(x) for x in line.split(',')]
        X.append(data[1:])
        y.append(data[0]) 

X = np.array(X)
y = np.array(y)

from sklearn import model_selection

X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y, test_size=0.25, random_state=5)

from sklearn.tree import DecisionTreeClassifier

classifier_DecisionTree = DecisionTreeClassifier()
classifier_DecisionTree.fit(X_train, y_train)
y_test_pred = classifier_DecisionTree.predict(X_test)

# compute accuracy of the classifier計算分類器的精確度
accuracy = 100.0 * (y_test == y_test_pred).sum() / X_test.shape[0]
print("Accuracy of the classifier =", round(accuracy, 2), "%")
X_test1 =[[1.51, 1.73, 1.98, 20.15, 85, 2.2, 1.92, .32, 1.48, 2.94, 1, 3.57, 172]]
X_test2 = [[14.23, 1.71, 2.43, 15.6, 127, 2.8, 3.06, .28, 2.29, 5.64, 1.04, 3.92, 1065]]
X_test3 = [[13.71, 5.65, 2.45, 20.5, 95, 1.68, .61, .52, 1.06, 7.7, .64, 1.74, 720]]


print(classifier_DecisionTree.predict(X_test1))
print(classifier_DecisionTree.predict(X_test2))
print(classifier_DecisionTree.predict(X_test3))

