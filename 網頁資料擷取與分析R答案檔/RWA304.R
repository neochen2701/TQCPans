# 讀入 read.csv
df <- read.csv("read.csv")

# 平均值
mean_value <- mean(df$data)
# 中位數
median_value <- median(df$data)
# 標準差
std_value <- sd(df$data)
# 變異數
var_value <- var(df$data)
# 極差值
range_value <- max(df$data) - min(df$data)
sprintf("平均值：%.2f", mean_value)
sprintf("中位數：%.2f", median_value)
sprintf("標準差：%.2f", std_value)
sprintf("變異數：%.2f", var_value)
sprintf("極差值：%.2f", range_value)
