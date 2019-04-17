# 載入 RSQLite 套件
library(RSQLite)

# 宣告資料庫名稱 read.db
db_file <- "read.db"

# 指定引擎為 SQLite
sqlite_driver <- dbDriver("SQLite")

# 建立連結
db <- dbConnect(sqlite_driver, dbname = db_file)

# 讀取 Employee 表格
employee <- dbReadTable(db, "Employee")

# 印出所有觀測值
n_rows <- nrow(employee)
for (i in 1:n_rows){
  print(employee[i, ])
}
