# 載入 xml.etree.ElementTree 模組並縮寫為 ET
import xml.etree.ElementTree as ET
# 載入 csv 模組
import csv

# 讀取 xml
tree = ET.parse("read.xml")
root = tree.getroot()

ubikefile = open("write.csv", "w", encoding='utf8')
csvwriter = csv.writer(ubikefile)

for row in root:
    ubike = []
    sno = row.find('sno').text
    ubike.append(sno)
    sna = row.find('sna').text
    ubike.append(sna)
    tot = row.find('tot').text
    ubike.append(tot)
    csvwriter.writerow(ubike)
ubikefile.close()
