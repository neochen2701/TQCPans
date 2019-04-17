# --開始--批改評分使用，請勿變動
set.seed(123)
# --結束--批改評分使用，請勿變動

samples1 <- rnorm(n = 1000, mean = 1, sd = 0.5)
samples2 <- rt(n = 1000, df = 10)

# 宣告圖檔名稱
png("chart.png")
# 分割畫布
par(mfrow = c(1, 2))
# 第一個子圖
bin_color_1 <- rgb(red = 0, green = 1, blue = 0, alpha = 0.5)
bin_color_2 <- rgb(red = 1, green = 0, blue = 0, alpha = 0.5)
hist(samples1, xlim = c(-4, 4), ylim = c(0, 200), breaks = 30, col = bin_color_1)
hist(samples2, add = TRUE, breaks = 30, col = bin_color_2)
legend("topright", legend = c("samples 1", "samples 2"),
       fill = c(bin_color_1, bin_color_2), box.lty = 0, bg = NA)

# 第二個子圖
plot(samples1, samples2)
dev.off()
