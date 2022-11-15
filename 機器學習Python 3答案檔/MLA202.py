import numpy as np
from sklearn.cluster import DBSCAN
from sklearn import metrics

input_file = ('data_perf.txt')
# Load data 載入資料
x = []
with open(input_file, 'r') as f:
    for line in f.readlines():
        data = [float(i) for i in line.split(',')]
        x.append(data)

X = np.array(x)


# Find the best epsilon 找最佳的epsilon
eps_grid = np.linspace(0.3, 1.2, num=10)
silhouette_scores = []
eps_best = eps_grid[0]
silhouette_score_max = -1
labels_best = None
for eps in eps_grid:
    # Train DBSCAN clustering model 訓練DBSCAN分群模型
    model = DBSCAN(eps=eps, min_samples=5).fit(X)

    # Extract labels 提取標籤
    labels = model.labels_

    # Extract performance metric  提取性能指標
    silhouette_score = round(metrics.silhouette_score(X, labels), 4)
    silhouette_scores.append(silhouette_score)

    print("Epsilon:", eps, " --> silhouette score:", silhouette_score)

    if silhouette_score > silhouette_score_max:
        silhouette_score_max = silhouette_score
        eps_best = eps
        model_best = model
        labels_best = labels

# Best params
print("Best epsilon =", eps_best)

# Associated model and labels for best epsilon
model = model_best 
labels = labels_best

# Check for unassigned datapoints in the labels
offset = 0
if -1 in labels:
    offset = 1

# Number of clusters in the data 
num_clusters = len(set(labels)) - offset 

print("Estimated number of clusters =", num_clusters)

# Extracts the core samples from the trained model
mask_core = np.zeros(labels.shape, dtype=np.bool)
mask_core[model.core_sample_indices_] = True


