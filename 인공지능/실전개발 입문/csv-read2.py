import csv, codecs

#CSV 파일 열기
filename="test.csv"
file=codecs.open(filename,"r","euc_kr")

#한 줄씩 읽어 들이기
reader=csv.reader(file,delimiter=",")
for cells in reader:
    print(cells[1],cells[2])
    