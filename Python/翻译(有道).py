import urllib.request
import urllib.parse
import json


while True:
    content = input('请输入需要翻译的内容（输入"q!"退出程序）：')
    if content =='q!':
        break
    
    
    url = 'http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule&sessionFrom=https://www.baidu.com/link'


    head = {}
    head['Use-Agent'] = 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.79 Safari/537.36'

    data = {
    'from':'AUTO',
    'to':'AUTO',
    'smartresult':'dict',
    'client':'fanyideskweb',
    'salt':'1500092479607',
    'sign':'c98235a85b213d482b8e65f6b1065e26',
    'doctype':'json',
    'version':'2.1',
    'keyfrom':'fanyi.web',
    'action':'FY_BY_CL1CKBUTTON',
    'typoResult':'true'}

    data['i'] = content
                
    data = urllib.parse.urlencode(data).encode('utf-8')

    req = urllib.request.Request(url, data, head)
    response = urllib.request.urlopen(req)
    html = response.read().decode('utf-8')

    target = json.loads(html)
    print("翻译结果：%s" % (target['translateResult'][0][0]['tgt']))

