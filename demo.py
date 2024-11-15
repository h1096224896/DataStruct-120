import requests


for i in range(1):
    response = requests.get("http://baidu.com")
    print(response.status_code)