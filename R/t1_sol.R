#q1
x = c(1,2,-1) # In R, c() function returns a vector

y = c(0.4,5,8)

A = matrix(c(
  4,-3,1,
  0.5,2,2,
  6,7,-2
),byrow=T,nrow=3) # byrow is True, which means data is filled by rows

B = matrix(c(
  -1,2,
  1,-2,
  3,1
),byrow=T,ncol=2)

#a
z = 2.3*x-y/7  #basic operator: + - * /
z
print(z,digits=2) # argument digits: minimal number of significant digits not decimal digits

#b
A %*% (2.3*x-y/7) # The operator %*% is used for matrix multiplication satisfying
# the condition that the number of columns in the first matrix is equal to the number 
# of rows in second.
A %*% (z)

#c
x %*% y
t(x) %*% y
crossprod(x,y)
#d
outer(x,y,'*') # 'Fun'='*' is handled as a special case visa as.vector(x)%*%t(as.vector(y))
x %*% t(y)

#e
solve(A) %*% B
solve(A,B)
# install.packages("matlib")
library("matlib")
inv(A) %*% B

#f
# R语言中的solve函数主要用于解决线性代数方程组，特别是求解矩阵方程。这个函数可以用来求逆矩阵，或者解线性方程组Ax = b
solve(A,x) # solve(a,b) solves the equation a%*%x=b
solve(A) %*% x

#q2
price = c(179000,126500,134500)
area = c(3060,1600,2000)
acres = c(0.75,0.26,0.7)
rooms = c(8,8,8)
baths = c(2.0,1.5,1)

homes = data.frame(price,area,acres,rooms,baths)

homes = data.frame(price = c(179000,126500,134500),
                   area = c(3060,1600,2000),
                   acres = c(0.75,0.26,0.7),
                   rooms = c(8,8,8),
                   baths = c(2.0,1.5,1))

#
homes = read.table(text="
price area acres rooms baths
179000 3060 0.75 8 2.0
126500 1600 0.26 8 1.5
134500 2000 0.7 8 1
",header=T)

#setwd("D:\\lectures\\6016\\tutorials\\t0")
#getwd()
saveRDS(homes,file="homes.RData")
home = readRDS("homes.RData")


#q3
testdat1 = read.csv(file="dat1.csv",header=T)

#q4
testdat2 = read.table(file="dat1.dat")
colnames(testdat2) = colnames(testdat1)


#q5
#setwd('D:\\courses\\6016\\2021\\chap0\\t0')
dat1 = readRDS(file="dat1.RData")

#a
dat1[2:5,]

#b
dat1[dat1$Age >= 45, c("Age","RunTime")]

#c
nrow(dat1)
ncol(dat1)
dim(dat1)

#d
dat1$ox2 = dat1$Oxygen^2

#e
dat1 = dat1[,-4]
dat1$RunTime = NULL

#f
mylist = list(x=x,A=A,homes=homes)
mylist$x
mylist[[1]]
names(mylist)

#q6
#a
A = cbind(x1 = 3, x2 = c(4:1, 2:5))

#b
mx1 = c()
for (i in 1:nrow(A)) {
  mx1 = c(mx1,mean(A[i,]))
}
mx1

mx1 = numeric(length = 8)
for (i in 1:nrow(A)) {
  mx1[i] = mean(A[i,])
}
mx1

#c
apply(A, 1, mean)

apply(A,2,mean)

#d
mym2 = function(i) {
  return(c(mean(A[i,]),sd(A[i,])))
}
mym2(2)

#e
(lm2 = lapply(1:nrow(A),mym2))
do.call(rbind, lm2)

#f
t(sapply(1:nrow(A),mym2))


# apply collection: apply(), lapply(), sapply(), tapply()
# apply collection can be viewed as a substitute to the loop.
# apply(X, margin,fun):
# X: an array or matrix
# margin=1 or 2: the manipulation is performed on rows or columns

# lapply(x,fun) function:
# x: a vector or an object
# lapply() function is useful for performing operations on list objects and returns
# a list object of same length of original set.

# sapply() function takes list, vector, or dataframe as input and gives output in vector or matrix


#Function	  Arguments	                    Objective	                                              Input	                            Output
#apply	    apply(x, MARGIN, FUN)	        Apply a function to the rows or columns or both	        Data frame or matrix              vector, list, array
#lapply	    lapply(X, FUN)	              Apply a function to all the elements of the input	      List,vector or data frame	        list
#sapply	    sapply(X, FUN)	              Apply a function to all the elements of the input	      List, vector or data frame	      vector or matrix
