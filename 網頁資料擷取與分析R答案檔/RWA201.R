clean_html_tags <- function(html_string) {
  return(gsub(pattern = "<.*?>", replacement = "", html_string))
}
get_word_cnt <- function(word_pattern) {
  words_cnt <- 0
  for (i in 1:length(html_doc)) {
    html_txt <- clean_html_tags(html_doc[i])
    words_positions <- gregexpr(pattern = word_pattern, html_txt, fixed = TRUE)
    if (words_positions[[1]][1] != -1) {
      how_many_words <- length(words_positions)
      words_cnt <- words_cnt + how_many_words
    }
  }
  return(words_cnt)
}

# 宣告網頁網址
page_url <- "https://www.codejudger.com/target/5201.html"

# 使用 readLines 函數讀取網頁
html_doc <- readLines(page_url)

# 宣告要計算的文字 TQC+
str_to_find <- "TQC+"
sprintf("%s 出現 %i 次", str_to_find, get_word_cnt(str_to_find))
