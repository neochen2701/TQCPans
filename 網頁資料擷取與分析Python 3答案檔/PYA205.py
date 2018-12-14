# 載入 requests 與 json 模組
import requests
import json

# 開放資料Json格式連結
url = 'http://tqc.codejudger.com:3000/target/5205.json'
# 發出Get請求
response = requests.get(url)
# 回傳內容長度
print('Content-Length:', response.headers['Content-Length'])
# 將取得的回傳內容轉換成Json格式
response = json.loads(response.text)

print()

# 顯示新北市每一個地區的PM2.5相關資料
print('新北市PM2.5相關資料：')
for record in response:
    # 判斷每一筆的County欄位，若為'新北市'則將相關訊息印出
    if record['County'] == '新北市':
        # 地區名稱 key 為 'SiteName'
        print('%s：' % record['SiteName'])
        # AQI指數 key 為 AQI
        print('\tAQI：%s' % record['AQI'])
        # PM2.5指數 key 為 PM2.5
        print('\tPM2.5：%s' % record['PM2.5'])
        # PM10指數 key 為 PM10
        print('\tPM10：%s' % record['PM10'])
        # 資料更新時間 key 為 PublishTime
        print('\t資料更新時間：%s' % record['PublishTime'])
