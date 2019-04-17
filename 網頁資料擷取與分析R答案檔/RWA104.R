# 載入 jsonlite 套件
library(jsonlite)

# 建立資料框
id <- c('1', '2', '3')
name <- c('Peter', 'Jack', 'Cindy')
country <- c('Taiwan', 'USA', 'Japan')
df <- data.frame(id, name, country)

# 建立清單
lst <- list()
lst[["people"]] <- df

# 寫出 write.json
json_str <- toJSON(lst)
writeLines(json_str, con = "write.json")
