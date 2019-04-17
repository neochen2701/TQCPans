df <- read.csv("read.csv")
scores <- df$scores
range_count <- rep(0, times = 5)
for (score in scores) {
  if (score < 20) {
    range_count[1] <- range_count[1] + 1
  } else if (score < 40) {
    range_count[2] <- range_count[2] + 1
  } else if (score < 60) {
    range_count[3] <- range_count[3] + 1
  } else if (score < 80) {
    range_count[4] <- range_count[4] + 1
  } else {
    range_count[5] <- range_count[5] + 1
  }
}
# X 軸刻度
labels <- c('0~19', '20~39', '40~59', '60~79', '80~100')
# Y 軸刻度
yticks <- seq(0, 25, 5)
png("chart.png")
barplot(range_count, names.arg = labels,
        main = "Score range count",
        xlab = "Range",
        ylab = "Quantity",
        yaxt="n")
axis(side = 2, at = yticks, labels = yticks)
dev.off()
