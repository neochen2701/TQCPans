# 載入 jsonlite 套件
library(jsonlite)

# 宣告資料連結
json_url <- "http://tqc.codejudger.com:3000/target/5204.json"
# 以 fromJSON 函數讀入資料連結
df <- fromJSON(json_url)
is_college <- df$type == "大專院校"
cols <- c("name", "address", "tel", "website", "update_date")
# 篩選大專院校與選擇欄位
college <- df[is_college, cols]
college
