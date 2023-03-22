import pandas as pd
import numpy as np

# t = pd.Series(np.arange(5))
#
# print(t)

t2 = pd.DataFrame(np.arange(12).reshape((3, 4)), index=list("abc"), columns=list("WXYZ"))

# t3 = np.array(t2)
# t4 = t3[1]
# t5 = t4.sort()
# print(t3)
# print(t4)
# print(t5)

# print(t2.loc[["a"]])
# print(type(t2.loc[["a"]]))
#
# t3 = t2.loc[["a"]]
# print(t3)
# print(t3.sort_values(by="X"))

# print(t2)
#
# t2 = t2.sort_values(by="X", ascending=0)
# print(t2)

# print(t2)
# print(type(t2))
# t4 = t2.head(2)
# print(t4)
# print(t2.head(2))
'''
dic = {"name": ["xiaoming", "xiaogang"], "age": ["32", "43"]}
dic2 = [{"name": "xiaoming", "age": 32}, {"name": "xiaogang", "age": 43}]

t3 = pd.Series(dic)
print(t3)

t4 = pd.DataFrame(dic)
print(t4)

t5 = pd.DataFrame(dic2)
print(t5) 
print(type(t4))
print(type(t5))'''

'''tick = {"name": ["周一", "周二"], "age": [32, 43]}
print(tick)

tick["tele"] = 123
tick["name"].append("牛逼")

print(tick)'''