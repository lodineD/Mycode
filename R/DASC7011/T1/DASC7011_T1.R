### Basic Arithmetic Calculation

# 12 times 4
12*4
# 63 divided by 7
63/7 
# remainder when 12 divided by 5
12%%5 
#squrae root of 4
sqrt(4) 
#square of 3
3^2 

# Introduction to Data Format in R
### Assignment

# Setting a variable called "a" to be 5
a = 3 
# replace the value 3 by 5
a = 5 

### Vector is a way to hold multiple values in a variable.
vec1=c(1,2,3)
vec2=c(4,5,6)
vec3=c(7,8,9)
vec4=c(vec1,vec2,vec3)
vec1
vec2
vec3
vec4

### Most data in statistics is in a "row-by-column" format
### which can be represented by a matrix. 
### We use cbind() and rbind() functions to bind either rows or columns together
mat1 = cbind(vec1, vec2)
mat2 = rbind(vec3, vec1, vec2)
mat1
mat2


### Another way to build a matrix is simply using "matrix" function. 
### Columns, rows or individual elements can be extracted with bracket notation, as shown below.

mat3 = matrix(vec4, nrow=3, ncol=3)
mat3
mat3[,1]
mat3[3,]
dim(mat3)

### Matrix operation
m = matrix(1:6, ncol=2)
m
n = matrix(1:6, ncol=2, byrow = T)
n
m+n
m-n
m*n
m/n
m^2
t(m)
t(m)%*%m

### In addition to the row by column format, most statistical datasets 
### have a mix of continuous and categorical variables. 
### To handle this in R, we need a data frame.

nrow = 12
# Generate a numeric variable with normal distribution
x1 = rnorm(n = nrow, mean = 0, sd=1)

# Generate a factor variable with 3 categories
fac1 = as.factor(rep(c("a","b","c"),each=4))

# Generate a data frame
df1 = data.frame(value = x1,category = fac1)
df1

# Look at the class of the attributes
class(df1$value)
class(df1$category)


############## Read & Write Data Files in R
### Function {getwd()} will help you get the current working directory
### Function {setwd('/Aimed Working Directory')} will help you set the working directory

getwd()
setwd("D:/tutorial/DASC7011/Tutorial/Tutorial_1st")
getwd()


### There are bunches of datafile types, the most frequent datafile format is ".csv" and ".txt". The following are examples to write your data.frame file into ".csv" and ".txt", respectively. 
write.csv(df1, file = "MyData.csv", row.names = FALSE)
write.table(df1, file = "MyData.txt", sep=",", col.names=TRUE)

### Load your files into R
read.csv("MyData.csv")
read.table("MyData.txt", sep=",")


########## Data Generation
?rnorm
?runif
?rbeta
?rt
?rf
?gamma


### Four ways to use the built-in distributions 
#### Probability density function (pdf) or probability mass function (pmf)

# Syntax: d + distribution name in R.
# It gives the value of the density function at the given value of x
dpois(2,lambda=3)

#### Cumulative density function (cdf) or cumulative mass function (cmf) 
# Syntax: p + distribution name in R 
# It gives the cumulative density at the given value of x
pnorm(0) 
pnorm(1.965)

####  Quantiles  
# Syntax: q + distribution name in R 
# It gives value of the quantile at the given cumulative density value
qnorm(0.5) 
qt(0.975,df=10)


#### Generating Pseudo random number
# Syntax: r + distribution name in R 
# It generates a given number of random numbers from specified distribution 

# Randomly generate 100 samples following normal distribution with mean 3 and standard deviation 1
x1 <- rnorm(n=100, mean=3, sd=1)
qqnorm(x1) #  plot normal qq plot
qqline(x1) #  add a reference line to the qq plot

# Generating 100 random numbers with F distribution df1=2 and df=5
x2 = rf(100,df1=2,df=5)



## Given x, generate $$y=(x+5)^{(e^{1.3}+N(0,0.1))}$$
x=seq(0.1,10,0.1)
##set.seed function: sets the starting number used to generate a sequence of 
##random numbers – it ensures that you get the same result 
##if you start with that same seed each time you run the same process. 
set.seed(7011)
rand = rnorm(100,0,0.1)
y = (x+5)^(exp(1.3)+rand)
cor(x,y)
plot(x,y)


### Basic Visualization histogram & Boxplot

par(mfrow=c(1,2))
hist(y, main = "Histogram")
boxplot(y, main = "Boxplot")


### Plot the data with fitted line
par(mfrow=c(1,1))
plot(x,y, pch=1, main="Observational Data (Simulated)")
fit1 = lm(y~x)
abline(fit1$coefficients,lwd=3, col=1)
yhat = (x+5)^(exp(1.3))
lines(x,yhat, lwd=3,  col=2)
lines(x,y, lwd=1, col=3)
legend('topleft', c("SLR Fitted","Default","Overfitted"), lwd=c(3,3,1), col=c(1,2,3))




library(MASS)
help(cats)
## This data frame contains the following columns: 
# Sex: Factor with levels "F" and "M".
# Bwt: body weight in kg.
# Hwt: heart weight in g.
# It is always a good idea to take a look of the data (if it’s not too large).

##You can always summaries a dataset to find the basic statistics
attach(cats)
summary(cats)

##Check how the dataset looks like.
dim(cats)
head(cats)
tail(cats)
names(cats)
class(Bwt)
class(Hwt)
class(Sex)


##The following are some useful functions
sub1 = subset(cats, Sex=='F')
sub2 = subset(cats, Bwt<=2.2)
sub3 = subset(cats, (Bwt<=2.5 & Hwt>=10))
mean(Bwt)
var(Bwt)
sd(Bwt)
sqrt(var(Bwt))
sort(Bwt)


##Do some basic plot, e.g. histogram & boxplot of Bwt & Hwt
par(mfrow=c(1,2))
hist(Bwt, main = "Histogram")
boxplot(Bwt, main = "Boxplot")

par(mfrow=c(1,2))
hist(Hwt, main = "Histogram")
boxplot(Hwt, main = "Boxplot")


##Do the basic scatterplot
plot(Bwt, Hwt)


##What about personalize your plot
plot(Bwt, Hwt, xlab = "Body Weight in kg", ylab="Heart Weight in g",
     main="scatterplot", type='n')
points(Bwt[Sex=='F'], Hwt[Sex=='F'], col="red", pch=1, cex=1)
points(Bwt[Sex=='M'], Hwt[Sex=='M'], col="blue", pch=2, cex=1)
legend("topleft",cex=1, legend= c("Female","Male"), col=c("red", "blue"), pch=c(1,2))


##Build up a simple linear regression model to Heart weight and Body weight
mod=lm(Hwt~Bwt,data=cats)
summary(mod)

##Look at the attributs in the model
attributes(mod)
mod$coefficients


##Find the confidence intervals of the coefficients
confint(mod)
confint(mod, level=0.99)


##Plot the fitted line to the points
plot(Bwt, Hwt, xlab = "Body Weight in kg", ylab="Heart Weight in g",
     main="scatterplot", type='n')
points(Bwt[Sex=='F'], Hwt[Sex=='F'], col="green", pch=3, cex=1)
points(Bwt[Sex=='M'], Hwt[Sex=='M'], col="purple", pch=4, cex=1)
legend("topleft",cex=1, legend= c("Female","Male"), col=c("green", "purple"), pch=c(3,4))
abline(mod, col='red',lwd=3)