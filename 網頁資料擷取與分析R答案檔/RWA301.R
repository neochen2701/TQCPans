# 載入 dplry 套件
library(dplyr)

# 資料輸入
chinese_scores <- c(75, 91, 71, 69)
math_scores <- c(62, 53, 88, 53)
english_scores <- c(85, 56, 51, 87)
science_scores <- c(73, 63, 69, 74)
ethic_scores <- c(60, 65, 87, 70)
students <- c("小林", "小黃", "小陳", "小美")
column_names <- c("學生", "國語", "數學", "英文", "自然", "社會")
df <- data.frame(students, chinese_scores, math_scores, english_scores, science_scores, ethic_scores)
# 更改欄位名稱
colnames(df) <- column_names
# 印出全部學生的成績
print("行標題為科目，列題標為個人的所有學生成績")
df
# 輸出後二位學生的所有成績
print("後二位的成績")
tail(df, n = 2)
# 將自然成績做遞減排序輸出
print("以自然遞減排序")
df %>% 
  arrange(desc(自然))

# 僅列小黃的成績，並將其英文成績改為80
df$英文[2] <- 80
print("小黃的成績")
df[2, ]
