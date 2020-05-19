# 載入 rvest 套件
library(rvest)

date_css_selector <- "tr:nth-child(n) td:nth-child(1)"
currency_css_selector <- "tr:nth-child(n) td:nth-child(2)"

# 讀入 html 檔案
html_doc <- read_html("read.html")

# 擷取 date_css_selector 所在的資料
date <- html_doc %>% 
  html_nodes(date_css_selector) %>% 
  html_text() %>% 
  `[` (-1)

# 擷取 currency_css_selector 所在的資料
NTD_USD <- html_doc %>% 
  html_nodes(currency_css_selector) %>% 
  html_text() %>% 
  `[` (-1) %>% 
  as.numeric()

# 宣告為資料框
df <- data.frame(date, NTD_USD)

# 寫出 csv 檔案
write.csv(df, file = "write.csv", row.names = FALSE)
