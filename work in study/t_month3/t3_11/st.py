import matplotlib.pyplot as plt
import random
from matplotlib import font_manager

my_font = font_manager.FontProperties(fname=r"c:\windows\fonts\msyh.ttc")


'''#数据获取
y_3 = [11,17,16,11,12,11,12,6,6,7,8,9,12,15,14,17,18,21,16,17,20,14,15,15,15,19,21,22,22,22,23]
y_10 = [26,26,28,19,21,17,16,19,18,20,20,19,22,23,17,20,21,22,20,15,11,15,5,13,17,10,11,13,12,13,6]

x_3 = range(1,32)
x_10 = range(51,82)

#绘图：

plt.figure(figsize=(20,8),dpi=80)

_x = list(x_3) + list(x_10)

_xlabel = ["3月{}日".format(i) for i in x_3] + ["10月{}日".format(i-50) for i in x_10]

plt.scatter(x_3,y_3,label="3月份")
plt.scatter(x_10,y_10,label="10月份")

plt.xticks(_x[::3],_xlabel[::3],rotation=45,fontproperties=my_font)

plt.xlabel("时间",fontproperties=my_font)
plt.ylabel("温度",fontproperties=my_font)
plt.title("空",fontproperties=my_font)


plt.legend(prop=my_font)
plt.show()
'''


#########################################################################
#显示中文问题：

'''

from matplotlib import font_manager

font = {'family' : 'MicroSoft YaHei',
        'weight' : 'bold',
        'size' : 'larger'}
matplotlib.rc("font",**font)
matplotlib.rc("font",family='MicroSoft YaHei',weight="bold  ")

my_font = font_manager.FontProperties(fname=r"c:\windows\fonts\msyh.ttc")

x = range(11,31)
y = [1,0,1,1,2,4,3,2,3,4,4,5,6,5,4,3,3,1,1,1]

plt.figure(figsize=(20,8),dpi=80)

_xlabel = ["{}岁".format(i) for i in x]

plt.plot(x,y,label="巧克力")
plt.xticks(x,_xlabel,rotation = 45,fontproperties=my_font)

plt.legend(prop=my_font)
plt.show()

'''

#########################################################################

'''x = range(0,120)
y = [random.randint(20,35) for i in range(120)]

plt.figure(figsize=(20,8),dpi=80)

plt.plot(x,y)

_xlabel = ["10h{}m".format(i) for i in range(60)]
_xlabel += ["11h{}m".format(i) for i in range(60)]

plt.xticks(list(x)[::3],_xlabel[::3],rotation = 45)

plt.show()'''

'''x = range(2,26,2)
y = [15,13,14.5,17,20,25,26,27,22,18,15,14]

plt.figure(figsize=(20,8), dpi=80)

plt.plot(x,y)
plt.show()'''