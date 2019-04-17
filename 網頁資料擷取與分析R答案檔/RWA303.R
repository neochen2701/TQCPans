# 載入 dplyr 套件
library(dplyr)

# 建構資料
water_melon_price <- c(9, 11.7, 10.1, 11.8, 13.2, 6.9, 12.1, 12, 11.7, 9.84)
water_melon_amount <- c(203674, 180785, 127802, 28604, 600, 38071, 35660, 15000, 48770, 6100)
melon_price <- c(13.2, 12.3, 14.7, 14.9, 13.1, 9.6, 10.6, 13, 9.1, 11.89)
melon_amount <- c(18894, 54894, 18563, 21963, 900, 3555, 9005, 12000, 14370, 8980)
market <- c("三重市", "台中市", "台北一", "台北二", "台東市", "板橋區", "高雄市", "嘉義市", "鳳山區", "豐原區")
column_names <- c("交易市場", "西瓜價", "西瓜量", "香瓜價", "香瓜量")
# 輸出拍賣行情價量表
df <- data.frame(market, water_melon_price, water_melon_amount, melon_price, melon_amount,
                 stringsAsFactors = FALSE)
colnames(df) <- column_names
print("西瓜與香瓜之拍賣行情價量表")
df
# 以西瓜價遞減排序後，輸出各市場的西瓜價
print("以西瓜價遞減排序")
df %>% 
  arrange(desc(西瓜價)) %>% 
  select(交易市場, 西瓜價)

# 計算台北一市場西瓜/香瓜價量的行情並輸出
print("台北一市場的行情")
df %>% 
  filter(交易市場 == "台北一")

# 將「三重市」改為「三重區」
df$交易市場[1] <- "三重區"
#「香瓜價」改為「洋香瓜價」
colnames(df)[4] <- "洋香瓜價"
#「香瓜量」改為「洋香瓜量」
colnames(df)[5] <- "洋香瓜量"
# 重新輸出整個表格
print('全體市場行情')
df
