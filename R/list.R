# list 用法
mylist = list(stu.id = 1234,
              stu.major = "DS",
              stu.marks = c(32, 434))
mode(mylist)

mode(mylist[[2]])

# 无论是否命名，list列表都会自动生成一个个列表名，这也就是为什么mode(mylist2[2])依然是“list”形式
mylist2 = list(1234, "DS", c(32, 434))
mode(mylist2[2])

names(mylist)
names(mylist) = c("id", "major", "marks")

# 不仅可以修改，还可以加
mylist$parents = c("zyd", "lxl")

# 指代期间有几个list
length(mylist)

# 合并list
sum_list = c(mylist, mylist2)

# display list
unlist(sum_list)
