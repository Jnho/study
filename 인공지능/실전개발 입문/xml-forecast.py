from bs4 import BeautifulSoup
import urllib.request as req
import os.path

#XML 다운로드
url="http://www.weather.go.kr/weather/forecast/mid-term-rss3.jsp?stnId=108"
savename="forecast.xml"
if not os.path.exists(savename):
    req.urlretrieve(url,savename) #실행 마다 xml 파일 내려 받으면 서버 부하. 그래서 request.urlretrieve() 사용

#BeautifulSoup로 XML 분석하기  
xml=open(savename,"r",encoding="utf-8").read()
soup=BeautifulSoup(xml,'html.parser') # html.parser는 HTML용, XML 태그 접근시 모두 소문자로 써야함

#각 지역 확인하기
info={}
for location in soup.find_all("location"):
    name=location.find('city').string
    weather=location.find('wf').string
    if not(weather in info):
        info[weather]=[]
    info[weather].append(name)

#각 지역의 날씨를 구분해서 출력하기
for weather in info.keys():
    print("+",weather)
    for name in info[weather]:
        print("| -",name)