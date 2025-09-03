import requests
import logging
import http.client

# 设置请求URL
url = 'http://172.18.18.61:8080/eportal/InterFace.do?method=login'

# 设置请求数据
    # 将userId中的example替换为自己的学号，例:U2023XXXXX
    # 将password中的example替换为自己的加密密码
    # 将queryString中的example替换为自己的校验码(需要在登录认证网页手动抓取)
    # 其他无需更改
data = {
    "userId": "example",      # 学号
    "password": "example",    # 加密密码
    "service": "",
    "queryString": "example",  # 校验码
    "operatorPwd": "",
    "operatorUserId": "",
    "validcode": "",
    "passwordEncrypt": "true",
}

# 发送 POST 请求
response = requests.post(url=url, data=data)

# 打印响应状态码
print(response.status_code)
