# JSON (JavaScript Object Notation)
#구조가 단순한 것이 장점. 인코딩/디코딩 표준으로 JSON 제공
#숫자 30    문자열 (큰 따옴표) "str"
#불 (true 또는 false) true      배열 [n1,n2,n3,...] [1,2,10,500]
#객체 { "key":value, "key":value, ...}  {"org":50, "com": 10} 
#null null null

import urllib.request as req
import os.path, random
import json

#JSON 데이터 내려받기
url="https://api.github.com/repositories"
savename="repo.json"
if not os.path.exists(url):
    req.urlretrieve(url,savename)

#JSON 파일 분석하기
items=json.load(open(savename,"r",encoding="utf-8"))
#또는
#s=open(savename,"r",encoding="utf-8").read()
#items=json.load(s)

#출력하기
for item in items:
    print(item["name"]+ "-"+item["owner"]["login"])