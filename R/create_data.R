

# 手动创建
mydata = data.frame(age = numeric(0),
                    gender = character(0),
                    weight = numeric(0))
mydata = edit(mydata)


# 读取txt文档,绝对地址双斜线
data = read.table("D:\\cs\\R\\Crash-1500.txt",
                  header = TRUE,
                  sep = ',')
data = edit(data)

# 读取csv文档
data = read.csv("D:\\cs\\R\\Data\\data_acute_cancer.csv",
                header = TRUE,
                sep = ',')
data  = edit(data)





# sql链接

# 加载包
library(RMySQL)
# 创建连接
con <- dbConnect(MySQL(),
                 user="root",
                 password="Zhudian2002!",
                 host="127.0.0.1",
                 port=3306,
                 dbname="test")

summary(con)
# 查
dbListTables(con)

#读
dbReadTable(con, 'Ticket')

#插入sql语句
dbSendStatement(con,"insert into user values('lgl', 213445, 48)")

# 关闭
dbDisconnect(con)
