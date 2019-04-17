# 載入 XML 套件
library(XML)

# 使用 xmlParse 函數讀取 xml 檔案
xml_doc <- xmlParse("read.xml")
xml_top <- xmlRoot(xml_doc)

# 使用 xmlToDataFrame 函數將 xml_top 轉換為資料框
df <- xmlToDataFrame(xml_top)

# 將sno（站點代號）、sna（中文場站名稱）、tot（場站總停車格）等三個欄位選出來
cols <- c("sno", "sna", "tot")
df <- df[, cols]

# 使用 write.table 輸出 write.csv
write.table(df, file = "write.csv", sep = ",",fileEncoding = 'UTF-8', col.names = FALSE, row.names = FALSE)
