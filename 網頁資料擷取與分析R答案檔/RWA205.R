# 載入 jsonlite 套件
library(jsonlite)

# 開放資料Json格式連結
json_url <- 'http://tqc.codejudger.com:3000/target/5205.json'
# 以 fromJSON 函數讀取 json_url
df <- fromJSON(json_url)
# 宣告篩選新北市的條件
is_new_taipei <- df$County == "新北市"
cols <- c("SiteName", "AQI", "PM2.5", "PM10", "PublishTime")
# 篩選出新北市與五個變數欄位
new_taipei <- df[is_new_taipei, cols]
new_taipei
