import openpyxl

filename="stat_104102.xlsx"
# print(book.get_sheet_names())
# print(book.get_sheet_by_name("stat_104102")) 도 가능
book=openpyxl.load_workbook(filename)

#맨 앞의 시트 추출하기
sheet=book.worksheets[0]

for row in sheet.rows:
    for data in row:
        print(data.value, end=" ")
    print("",end="\n")