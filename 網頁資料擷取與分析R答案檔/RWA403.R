# 四個月份
month_labels <- c('Jun', 'Jul', 'Aug', 'Sep')
sizes <- c(20, 30, 40, 10)
# 宣告圖檔檔名
png("chart.png")
# 切割畫布為 1x2
par(mfrow = c(1, 2))
# 長條圖
barplot(sizes, names.arg = month_labels)
# 圓餅圖
size_labels <- paste0(sprintf("%.1f", sizes), "%")
pie_labels <- paste(month_labels, "\n", size_labels)
pie(sizes, labels = pie_labels)
dev.off()
