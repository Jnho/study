import openpyxl

#엑셀 파일 열기
filename="stat_104102.xlsx"
book=openpyxl.load_workbook(filename)

#활성화된 시트 추출하기
sheet=book.active

for i in range(0,10):
    total=int(sheet[str(chr(i+66))+"4"].value)
    seoul=int(sheet[str(chr(i+66))+"5"].value)
    
    output=total-seoul
    print("서울 제외 인구=",output)
    #쓰기
    sheet[str(chr(i+66))+"22"]=output
    cell=sheet[str(chr(i+66))+"22"]
    #폰트와 색상 변경해보기
    cell.font=openpyxl.styles.Font(size=14,color="FF0000")
    cell.number_format=cell.number_format

#엑셀 파일 저장하기
filename="population.xlsx"
book.save(filename)
print("ok")