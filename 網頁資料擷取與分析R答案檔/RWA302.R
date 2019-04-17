# --開始--批改評分使用，請勿變動
set.seed(123)
# --結束--批改評分使用，請勿變動

# 隨機產生5~15之間，15個正整數
x <- sample(5:15, size = 15, replace = TRUE)
print("隨機正整數：")
x
# 轉成3×5的X矩陣
X <- matrix(x, nrow = 3, ncol =5)
print("X矩陣內容：")
X
# 使用 max(), min(), sum()函數計算
sprintf("最大：%i", max(X))
sprintf("最小：%i", min(X))
sprintf("總和：%i", sum(X))
# 將 X 四個角落元素放入 corners
corners <- matrix(nrow = 2, ncol = 2)
corners[1, 1] <- X[1, 1]
corners[2, 1] <- X[3, 1]
corners[1, 2] <- X[1, 5]
corners[2, 2] <- X[3, 5]
print("四個角落元素：")
corners
