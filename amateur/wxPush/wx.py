import requests
sckey = 'SCU156533T19abe13eb52ac1247450dfd04f1c642c60154207bd775'#在发送消息页面可以找到
url = 'https://sc.ftqq.com/%s.send?text=程序完成了&desp=好玩吧'%sckey
res = requests.get(url)
print(res)