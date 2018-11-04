# 微信聊天机器人

import itchat, time

# 只注册文本信息，图片是PICTURE，语音是RECORDING，名片对应CARD
@itchat.msg_register(itchat.content.TEXT)

# 只打印接受到的消息
def print_content(msg):
    print(msg['Text'])

itchat.auto_login(hotReload = True)

friendList = itchat.get_friends(update=True)[1:]
for friend in friendList:
    print(friend['DisplayName'] + ' ' + friend['NickName'] + friend['UserName'])
    print('\n')

# itchat.send(u'我要次烧烤!', 'filehelper')
# 给DSS发消息
#while(True):
    # itchat.send(u'我要次烧烤!', '@6ad8d381f7c64ae9dfba55c58bfcbb354e503c565182ad3d9e61b08199d2b1af')
#    itchat.send(u'老板最帅', '@b3976547994360229d442551c379d41138083a42b333fd78db2708963fc41097')
#    time.sleep(5)

itchat.run()
