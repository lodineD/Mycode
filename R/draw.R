library(RMySQL)

con = dbConnect(
  MySQL(),
  user = "root",
  password = "Zhudian2002!",
  host = "127.0.0.1",
  port = 3306,
  dbname = "test"
)

v1 = c(20, 30, 40, 45, 60)
v2 = c(16, 20, 27, 40, 60)
v3 = c(15, 18, 25, 31, 40)

for (i in 1:length(v1)) {
  # paste会把所有的东西变成string，要这样转换
  command = paste("insert into medicine values(", v1[i], ",", v2[i], ",", v3[i], ")", sep =
                    "")
  
  dbSendStatement(con, command)
  
}

#储存默认变量，用于回档画图默认值
opar = par(no.readonly = TRUE)
#par用来指定画图规格，lty=2为变虚线，pch=17为变三角形
par(lty = 2, pch = 17)

# 画图
plot(v1, v2, type = "b")

# 第二种，用的多
plot(v1,
     v2,
     type = "b",
     lty = 2,
     pch = 19)

# 回到默认值
par(opar)

# 常用的画图内容
library(png)
imgpng <- readPNG("D:/cs/R/Data/plot.png")
r <- nrow(imgpng) / ncol(imgpng)
plot(
  c(0, 1),
  c(0, r),
  type = "n",
  xlab = "",
  ylab = "",
  asp = 1
)
rasterImage(imgpng, 0, 0, 1, r)


# 绘制颜色
library(png)
imgpng2 <- readPNG("D:/cs/R/Data/color.png")
r2 <- nrow(imgpng2) / ncol(imgpng2)
plot(
  c(0, 1),
  c(0, r2),
  type = "n",
  xlab = "",
  ylab = "",
  asp = 1
)
rasterImage(imgpng2, 0, 0, 1, r2)

# cex指缩放倍数，lty为线条类型，lwd为线条宽度，详见line44所给图
plot(
  v1,
  v2,
  type = "b",
  lty = 6,
  lwd = 3,
  pch = 11,
  cex = 3,
  col = "blue"
)

# 文本参数
library(png)
imgpng3 = readPNG("D:/cs/R/Data/font-cex.png")
r = nrow(imgpng3) / ncol(imgpng3)
plot(
  c(0, 1),
  c(0, r),
  type = "n",
  xlab = "",
  ylab = "",
  asp = 1
)
rasterImage(imgpng3, 0, 0, 1, r)

# 画图精细化
library(Hmisc)
plot(v1, v3, type = "b", col="red", lty=2)
# 这个函数用于把坐标次要刻度划分，nx为3份，ny为2份，ick.ratio是长度比例，0.5表示次刻度是主刻度的一半
minor.tick(nx = 3,
           ny = 2,
           tick.ratio = 0.5)

# 添加参考线
abline(h = 2, lty = 2, col = "red") # h高度处
abline(v = 2, lty = 2, col = "blue")# v长处

# 添加线
lines(v1, v2, lty=1, col="blue", type="b", pch=17)
