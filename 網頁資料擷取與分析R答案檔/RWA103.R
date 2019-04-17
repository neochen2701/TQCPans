# 載入 yaml 與 jsonlite 套件
library(yaml)
library(jsonlite)

# 使用 fromJSON 函數讀入 read.json
df <- fromJSON("read.json")

# 使用 as.yaml 函數將資料框轉換為 YAML 字串
yaml_str <- as.yaml(df, column.major = FALSE)

# 使用 writeLines 函數將 YAML 字串輸出為 write.yaml
writeLines(yaml_str, con = "write.yaml")
