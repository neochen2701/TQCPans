# 載入 rvest 套件
library(rvest)

lottery_numbers_selector <- ".dotted01+ .contents_box02 .ball_yellow"
special_numbers_selector <- ".ball_yellow+ .ball_red"
# 宣告網頁網址
page_url <- "https://www.codejudger.com/target/5203.html"
# 使用 read_html 函數讀取網頁
html_doc <- read_html(page_url)
print("大樂透開獎 : ")
print("-------------")
# 指定 lottery_numbers_selector
html_doc %>% 
  html_nodes(lottery_numbers_selector) %>% 
  html_text() %>% 
  as.numeric() %>% 
  `[` (1:6)
print("大小順序 : ")
# 指定 lottery_numbers_selector
html_doc %>% 
  html_nodes(lottery_numbers_selector) %>% 
  html_text() %>% 
  as.numeric() %>% 
  `[` (7:12)
print("特別號 : ")
# 指定 special_numbers_selector
html_doc %>% 
  html_nodes(special_numbers_selector) %>% 
  html_text() %>% 
  as.numeric()
