from matplotlib import pyplot as plt
from sklearn.datasets.samples_generator import make_blobs
from sklearn.cluster import KMeans

#  載入scikit-learn資料集範例資料
X, y = make_blobs(n_samples=200, 
                  centers=4, 
                  cluster_std=0.50, 
                  random_state=0)
plt.scatter(X[:,0], X[:,1])
print(X)
#inertia_集群內誤差平方和，做轉折判斷法的依據
Wcss_data = []
for i in range(1, 8):
    #實作
    kmeans = KMeans(n_clusters=i, 
                    init='k-means++', 
                    max_iter=200, 
                    n_init=15, 
                    random_state=0)
    kmeans.fit(X)
    Wcss_data.append(kmeans.inertia_)
print(Wcss_data)
    

kmeans = KMeans(n_clusters=4, 
                init='k-means++', 
                max_iter=200, 
                n_init=15, 
                random_state=0)
#kmeans_fit=kmeans.fit(X)

kmeans_predict = kmeans.fit_predict(X)
print("cluster_centers=",kmeans.cluster_centers_)

