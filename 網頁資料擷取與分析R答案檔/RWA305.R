# 載入 dplyr 套件
library(dplyr)

# 讀取csv檔
df <- read.csv("read.csv", na.strings = "None")
# 居住縣市病例人數，並按遞減順序顯示
df %>% 
  group_by(居住縣市) %>% 
  summarise(病例人數 = n()) %>% 
  arrange(desc(病例人數))
# 顯示感染病例人數最多的5個國家，並按遞減順序顯示
df %>% 
  group_by(感染國家) %>% 
  summarise(病例人數 = n()) %>% 
  arrange(desc(病例人數)) %>% 
  head(5)
# 台北市各區病例人數
df %>% 
  filter(居住縣市 == "台北市") %>% 
  group_by(居住鄉鎮) %>% 
  summarise(病例人數 = n())
# 台北市最近病例的日期
df %>% 
  filter(居住縣市 == "台北市") %>% 
  mutate(發病日日期格式 = as.Date(發病日)) %>% 
  summarise(max(發病日日期格式))
