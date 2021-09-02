import csv
import matplotlib.pyplot as plt
# 開啟 CSV 檔案
x=[]
with open('record.csv', newline='') as csvfile:

    # 讀取 CSV 檔案內容
    rows = csv.reader(csvfile)

    # 以迴圈輸出每一列
    for row in rows:
        for i in range(len(row)):
            print(i)
            row[i] = int(row[i])
        x.append(row)
for i in range(len(x)):
    
    if len(x[i])==101:
        plt.plot(range(len(x[i])-1), x[i][1:101]) #第一組不劃出 圖太醜
plt.show()