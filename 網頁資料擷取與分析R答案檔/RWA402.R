# 讀入資料
df <- read.csv("read.csv", header = FALSE)
col_names <- c("date", "price")
# 宣告變數名稱
colnames(df) <- col_names
# 宣告圖檔名稱
png("chart.png")
plot(1:7, df$price, 
     col = "blue", 
     type = "l",
     main = "Market Average Price",
     xlab = "date",
     ylab = "NT$",
     ylim = c(15, 25),
     xaxt="n")
xtick <- as.character(df$date)
axis(side = 1, at = 1:7, labels = xtick)
dev.off()
