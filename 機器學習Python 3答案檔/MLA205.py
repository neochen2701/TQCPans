import json
import pandas as pd
import numpy as np
from sklearn import covariance, cluster
symbol_file = 'symbol_map.json'

with open(symbol_file, 'r') as f:
    symbol_dict = json.loads(f.read())

symbols, names = np.array(sorted(symbol_dict.items())).T

quotes = []

for symbol in symbols:
    quotes.append(pd.read_csv(symbol+'.csv'))
closing_quotes = np.vstack([q['close'] for q in quotes])
opening_quotes = np.vstack([q['open'] for q in quotes])

# The daily fluctuations of the quotes  報價的每日波動
delta_quotes = closing_quotes - opening_quotes

# Build a graph model from the correlations
edge_model = covariance.GraphicalLassoCV(cv=3)

# Standardize the data 標準化資料
X = delta_quotes.copy().T
X /= X.std(axis=0)

# Train the model 訓練模型
with np.errstate(invalid='ignore'):
    edge_model.fit(X)

# Build clustering model using affinity propagation  用相似性傳播構建分群模型
_, labels = cluster.affinity_propagation(edge_model.covariance_)
num_labels = labels.max()

# Print the results of clustering 列印分群結果
for i in range(num_labels + 1):
    print("Cluster", i+1, "-->", ', '.join(names[labels == i]))
    


