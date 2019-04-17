# 資料
data1 <- c(1, 4, 9, 16, 25, 36, 49, 64)
data2 <- c(1, 2, 3, 6, 9, 15, 24, 39)
seq <- c(1, 2, 3, 4, 5, 6, 7, 8)

# 宣告圖檔名稱
png("chart.png")
# 繪製 seq vs. data1
plot(seq, data1,
     type = "b",
     col = "blue",
     xlim = c(0, 8),
     ylim = c(0, 70),
     main = "Figure",
     xlab = "x-value",
     ylab = "y-value")
# 繪製 seq vs. data2
lines(seq, data2, type = "b", col = "red")
dev.off()
