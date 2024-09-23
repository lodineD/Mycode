#######################################################

############## R Workshop for Beginners ###############

#######################################################

# Chapter 1. Introduction

# Simulating the circumference pi
# as 4 times the inverse ratio of areas
# of a square and its inscribed circle
pi.sim <- function(n) { # Define as a function
  x <- runif(n,-1,1)  # n random x-coordinates
  y <- runif(n,-1,1)  # n random y-coordinates
  covered <- as.numeric(x^2+y^2<1)
      # Indicator of (x,y) falling in the unit circle
  pi.hat <- mean(covered)*4
  pi.hat        # Output pi
}   # End of definition of function 
# Execution of the function
pi.sim(1000)
pi.sim(1000000)


########################################################

# Chapter 2. R Commands and Objects

########################################################

# 2.1 Use help
?bptest
help(bptest)
??bptest
help.start()
help.start

# 2.2 Create R objects
# Display and remove objects
objects()
rm(pi.sim)
ls()

# Define empty variable/vector/matrix
y1 <- numeric(); y1
y2 <- character(5); y2
y3 <- logical(2); y3
A <- matrix(nrow = 2, ncol = 3); A

# An example of character variable/vector
c(1:3, "String", NA, 0/0, 1/0, -1/0, TRUE, FALSE)

# An example of numeric variable/vector
c(1:3, NA, 0/0, 1/0, -1/0, TRUE, FALSE)

# 2.3 Assign values to variables
# Assign scalar values
a <- 1; a               # Numeric
b = 2; b
a = b; a; b             # To see what happen
2 -> a; a
c <- "MStat"; c         # Character
d <- a>2; d             # Logical

# Assign vectors
x1 <- c(4, 2, 0); x1                # Numerical vector
c(1, 0, -1) -> x2; x2               # Numerical vector
assign("x3", c("A", "B", "C")); x3  # Character vector
x4 <- x1>=2; x4                     # Logical vector
f <- factor(c("A", "B","C", "A")); f      # Factor vector
c1 <- 1+2i; c1                      # Complex number
mode(c1)
c2 <- c(1-i, 4+2i); c2              # Incorrect usage
c <- complex(2, c(1,4), c(-1,2)); c # Correct usage
View(a)                             # View a in editor
View(x1)                            # View x1 in editor
x2[2]                               # 2nd value of x2
x3[3]                               # 3rd value of x3
x1[c(1,3)]                          # 1st and 3rd values of x1

# Connect vectors to a new vector
x5 <- c(x1, 0, x2); x5            # 7-dimensional vector

# Generate regular sequences
x6 <- 1:6; x6
seq(from=0, to=20, by=5)
seq(from=2, by=-1, length=7)
rep(x1, times=3)
rep(x1, each=3)

# 2.4 Assign matrices
m1 <- matrix(c(x1, x2), nrow=3, ncol=2); m1 # Read by column
M1 <- cbind(x1, x2); M1                     # Combine by columns
m2 <- matrix(c(x1, x2), nrow = 2, ncol = 3, 
             byrow = T); m2                 # Read by row
M2 <- rbind(x1, x2); M2                     # Combine by rows
# One more example of rbind() and cbind()
cbind(0, rbind(1, 1:3))
# Display row(s), column(s), or element(s) of a matrix
m1[1,]                        # 1st row of m1
m1[,2]                        # 2nd column of m1
m1[1,2]                       # (1,2)th element of m1
m1[2:3,1]                     # Values in rows 2 & 3, column 1

# 2.5 Define a data frame (data set)
data1 <- data.frame(x1, x2); View(data1)      # Define
data2 <- data.frame(X=x1, Y=x2); View(data2)  # Define and rename

# Add a variable (with the same length) to the data frame
data1$XX <- x3
View(data1)
data1$XX



# 2.6 Modes of objects
mode(x1)
mode(x3)
mode(x4)
mode(c)
mode(f)
mode(m1)
mode(M1)
mode(data1)
# lengths of vectors or data frames
length(x1)
length(data2)
# length of a matrix
length(m1)
# orders of a matrix
nrow(m1)
ncol(m1)
# orders of a data frame
nrow(data2)
ncol(data2)
# Change modes
x1; as.character(x1)
x4; as.numeric(x4)
# Change types
m2; as.data.frame(m2)
data2; as.matrix(data2)

# 2.7 Define Arrays
# Define an empty array
A3 <- array(,dim = c(2,3,2)); A3
# See how values are put into the array
A3 <- array(1:12,dim = c(2,3,2)); A3
# Assign m2 as values of A3[,,1]
A3[,,1] <- m2; A3[,,1]
# Assign other numeric values
A3[,1,2] <- 0; A3
# Assign other character values
A3[,2,2] <- "B"; A3
# Display/Use values
A3[2,c(1,3),1]




# Training exercises
# Q1.a)
TX1 <- seq(from=3, to=50, by=7); TX1
# Q1.b)
TX2 <- seq(from=45, to=0, by=-7); TX2
# Q1.c)
TX3 <- c(TX1, TX2); TX3
# Q1.d)
TX4 <- rep(TX1, 2); TX4
# Q1.e)
TX5 <- rep(TX2, each=2); TX5
# Q1.f)
TX6 <- rep(c("F","F","M"),5)[1:length(TX5)]; TX6
# Q1.g)
TX7 <- as.factor(TX6); TX7
# Q2.a)
TM1 <- matrix(c(TX1, TX2), length(TX1), 2); TM1
# Q2.b)
TM2 <- matrix(c(TX4, TX5), 2, length(TX4), byrow = T); TM2
# Q3.a)
TD1 <- data.frame(V1=TX4, V2=TX5); View(TD1)
# Q3.b)
TD2 <- data.frame(TD1, V3=TX6); View(TD2)
# Q4.a)
TX1[c(2,4)]
# Q4.b)
TM1[c(3,4),2]
# Q4.c)
nr=nrow(TD2); nc=ncol(TD2);TD2[c(nr-1,nr),c(nc-1,nc)]


########################################################

# Chapter 3 Simple Computations and Manipulations

########################################################

# 3.1 Computations of scalars
x1; a; x1-a
x1; b; x1*b
x1; x1^2
x1; x2; x1-x2
x1*x2
x1/x2
x5; 1/x5
sum(x1)
prod(x1)
log(x1)
exp(x1)
x1; m1; x1*m1
m2; x2; m2*x2
x1; x5; x1*x5



# 3.2 Computations of matrices
m1
nrow(m1)
ncol(m1)
t(m1)                   # transpose
diag(m1)                # diagonal elements
b <- c(1,2,3); diag(b)  # diag(1,2,3) in mathematics
diag(c(1,2,3))          # Equivalent use
diag(1,2,3)             # A 2 by 3 matrix with diagonal  
                        # elements being 1
diag(3)                 # identity matrix of order 3
A <- m1%*%t(m1); A      # matrix multiplication
t(m1)%*%m1
X1 <- as.matrix(x1)     # A column vector of dimension 3
nrow(X1); ncol(X1)      # Dimensions of X1
X2 <- t(as.matrix(x2))  # A row vector of dimension 3
X2%*%X1                 # Inner product
X1%*%X2                 # Outer product
solve(A)                # inverse of singular matrix
A[3,3] <- 10; solve(A)  # inverse of non-singular matrix
solve(A, b)             # Solve A%*%X=b
solve(A, m1)            # Solve A%*%X=m1
det(A)                  # Determinant of A
A.eigen <- eigen(A)     # Eigenvalues and eigen vectors of A
A.eigen
# Check the eigenvalues and eigenvectors
A%*%A.eigen$vectors
A.eigen$values[1]*A.eigen$vectors[,1]
A.eigen$values[2]*A.eigen$vectors[,2]
A.eigen$values[3]*A.eigen$vectors[,3]




# 3.3 Computations of logical vectors
c1 <- x1!=2; x1; c1
c2 <- x2<=0; x2; c2
c3 <- x1=x2
c3 <- x1==x2; c3
c1 & c2
c1 | c2
c1 | c2 & c3        # AND superior to OR
c1 | (c2 & c3)      # Equivalent to the previous
(c1 | c2) & c3




# 3.4 Manipulations of vectors
v <- c(1:3); v          # Original vector
v[2:3] <- c(4,5); v     # Change values
v[5] <- 4; v            # Change length by adding values
v1 <- v[2:4]; v1        # The 2nd to the 4th values
v2 <- v[c(2,4)]; v2     # The 2nd and 4th values
v3 <- v[-c(2,4)]; v3    # Delete the 2nd and 4th values
v[v<4]                  # Values less than 4




# 3.5 Manipulations of matrix
m <- matrix(1:9, nrow=3, ncol=3); m
m[2:3,]           # Last 2 rows
m[,c(1,3)]        # The 1st and 3rd columns
m[,m[1,]<5]       # Columns with values in the 1st row <5
m[m[,1]>1,]       # Rows with values in the 1st column >1
con <- as.vector(m); con  # Concatenation




# 3.6 Manipulations of characters 
# Character vectors
a <- c('Tutorial',"in",'R'); a
paste('Tutorial',"in",'R')  # Concatenate
cat('Tutorial',"in",'R')    # Concatenate and print
paste("Today is", date())
paste(c("X","Y"), 1:5, sep="o")




# Factors
state <- c("tas", "sa",  "qld", "nsw", "nsw", "nt",  "wa",  
           "wa", "qld", "vic", "nsw", "vic", "qld", "qld", 
           "sa",  "tas", "sa",  "nt",  "wa",  "vic", "qld", 
           "nsw", "nsw", "wa", "sa",  "act", "nsw", "vic", 
           "vic", "act")
statef <- factor(state); statef
levels(statef)




# A numerical variable can also be treated as/converted 
# to a factor variable
factor(c(1,2,3,3,2,2,1))
# Equivalent usages
as.factor(c(1,2,3,3,2,2,1))
fac <- factor(c(1,2,3,3,2,2,1)); fac




# 3.7 Manipulations of data frames
data1
# List values of ONE variable
data1$x1            # Values of variable x1
data1[,1]           # Values of the 1st variable
# Cite variable(s)
data1[1]            # The 1st variable
data1[1:2]          # The 1st to the 2nd variables
data1[,1:2]         # The 1st to the 2nd variables
data1[c(1,3)]       # The 1st and the 3rd variables
# Cite observations
data1[1,]           # The 1st observation
data1[1:2,]         # The 1st to the 2nd observations
data1[c(1,3),]      # The 1st and the 3rd observations
# Select observations with restriction(s)
data1[data1$x1<1,]  # Observations with x1<1
data1[data1$x2>0,]  # Observations with x2>0
# Define a new data frame with more variables and observations
# for the following manipulations
v1 <- rep(1:3,3)
v2 <- rep(1:3, each=3)
v3 <- 1:9; v3[8] <- NA
data2 <- data.frame(v1, v2, v3)
View(data2)
# Remove omitted values
data3 <- na.omit(data2); View(data3)
# Remove the 3rd and 5th observations
data3 <- data3[c(-3,-5),]; View(data3)
# Reorder the data frame by values of v1
data3[order(data3$v1),]                   # Ascending order
data3[order(data3$v1, decreasing = T),]   # Descending order
data3[order(-data3$v1),]                  # Descending order
# Reordered by more than one variable
data3[order(data3$v2, -data3$v1),]
# Reorder the data frame from the last 
# to the first observation
data2$Obs <- 1:nrow(data2)          # Add the natural order


data2[order(-data2$Obs),]           # Descending order

# Save selected R object(s)
SEL <- list(A, data1, A.eigen, pi.sim)
View(SEL)
names(SEL) <- c("Matrix", "Data_Frame", 
                "Estimation", "Function")
View(SEL)
save(SEL, file = "C:/Teaching/R Workshop/R_SEL.Rdata")
# Load the saved file
rm(SEL)
load("C:/Teaching/R Workshop/R_SEL.Rdata")
# Apply/Use saved R object
SEL$Matrix; SEL$Data_Frame$x1

# 3.8 Probabilities and distributions
# Consider N(2, 0.5^2) as example
pnorm(2.3, mean = 2, sd = 0.5, lower.tail = T, log.p = F)
pnorm(1:3, 2, 0.5)            # Three probabilities
pnorm(2.3, 2, 0.5, log.p = T) # Logarithm of probability
                              # NOT probability of log-normal
dnorm(2.3, 2, 0.5)            # Normal(2, 0.5^2)
qnorm(0.95, 2, 0.5)           # Left 95% or right 5% quantile
rnorm(5, 2, 0.5)              # Generate 5 random numbers
# Random numbers with a fixed seed
set.seed(1234)
RN <- rnorm(5000, 2, 0.5); RN
# Random numbers with a new seed
set.seed(4321)
rnorm(5, 2, 0.5)
# Joint density/Likelihood of RN
like <- prod(dnorm(RN,2,0.5)); like
# Log-likelihood of RN
log(like)
loglike <- sum(dnorm(RN,2,0.5,log=T)); loglike

# 3.9 Reading or Loading data
# Set and change working directory
setwd("C:/Teaching/R Workshop")
getwd()         # Display the working directory
list.files()

# Reading data from ~.txt or ~.dat files
read.table('house.txt') -> house1  # Without variable names
View(house1); names(house1)
read.table('house.txt',header=TRUE) -> house2  # With variable names
View(house2); names(house2)

# Read data from ~.csv files
read.csv('house.csv') -> house3

# Read data from ~.xlsx or ~.xls files
require(readxl)
read_excel('house.xlsx') -> house4
read_excel('house.xls') -> house5

# Rename variables in a data frame
names(house5)[1] = "P"
names(house5)[2] = "T"
View(house5)
names(house5)[3:5] <- c("L", "S", "A")

# Write an R data frame into an Excel .csv file
write.csv(house5, file = "house5.csv")

# Loading data from other R packages
data(package="rpart")         # List all data files
data(solder,package="rpart")  # Read a data file
solder                        # Activate and display the data
View(solder)                  # Activate and view the data


########################################################

# Chapter 4. Elementary Statistics Using R

########################################################

# 4.1 Descriptive statistics
# Iris data
dat <- iris; View(dat)
names(dat) <- c("SL", "SW", "PL", "PW", "Sp")

# Summary
summary(dat) 
summary(dat$SL)
summary(dat$Sp) 
summary(dat[,-5])

# Means
mean(dat$SL)            # Mean of a variable
mean(dat)               # Doesn't work
mean(dat[,1:4])         # Doesn't work
apply(dat,2,mean)       # Warning: not numeric
apply(dat[,1:4],2,mean) # Mean of each column
apply(dat[,1:4],1,mean) # Mean of each row

# Other statistics
min(dat$SL)             # Minimum
max(dat$SL)             # Maximum
range(dat$SL)           # built-in range
max(dat$SL)-min(dat$SL) # Range
mean(dat$SL)            # Mean
median(dat$SL)          # Median
quantile(dat$SL,0.25)   # 1st quartile
quantile(dat$SL,0.75)   # 3rd quartile
IQR(dat$SL)             # Interquartile range
var(dat$SL)             # Variance
sd(dat$SL)              # Standard deviation
cov(dat$SL, dat$SW)     # Covariance
cov(dat[,1:4])          # Covariance matrix
cor(dat$SL, dat$SW)     # Correlation
cor(dat[,1:4])          # Correlation matrix
library(e1071)
skewness(dat$SL)        # Skewness
kurtosis(dat$SL)        # Kurtosis

# Descriptive statistics by group
by(dat$SL, dat$Sp, summary)

# 4.2 Contingency tables
# Creative one more categorical variable
dat$size <- ifelse(dat$SL < mean(dat$SL), "small", "large")

# One-dimension contingency tables
table(dat$size)               # Frequencies
proportions(table(dat$size))   # Proportions

# Two-dimension contingency tables
# Frequencies
table(dat$Sp, dat$size) 
# Proportions
proportions(table(dat$Sp, dat$size))
# Round-off the proportions
round(proportions(table(dat$Sp, dat$size)),2)
# Row proportions
proportions(table(dat$Sp, dat$size),1)
# Column proportions
proportions(table(dat$Sp, dat$size),2)
# An alternative way
xtabs(~ Sp + size, data=dat)

# Visualization of contingency tables
mosaicplot(table(dat$Sp, dat$size), color = TRUE,
           xlab = "Species", ylab = "Size")
mosaicplot(table(dat$size))
mosaicplot(xtabs(~ Sp + size, data=dat))          
           
# 4.3 Descriptive plots

# Barplots of contingency tables
barplot(table(dat$size))  # table() is mandatory
barplot(proportions(table(dat$size)))
barplot(table(dat$Sp,dat$size)) # Stacked bar chart
barplot(table(dat$size,dat$Sp))

# Save tables
table1 <- table(dat$size)
table2 <- table(dat$size,dat$Sp)
# Barplots with color
barplot(table1, col=c("blue", "yellow"))
# Horizontal barplots 
barplot(table1, col=c("blue", "yellow"), horiz=T)
# Stacked barplot with legend
barplot(table2, col=c("blue", "yellow"),
        legend.text = c("large", "small"),
        ylim = c(0,80))
# Grouped barplot with legend
barplot(table2, col=c("blue", "yellow"),
        legend.text = c("large", "small"),
        ylim = c(0,80), beside = T)

# Default histogram
hist(dat$SL, main = "Histogram of frequencies")
hist(dat$SL, prob=T, main = "Histogram of probabilities")
# Make the bins smaller
hist(dat$SL, prob=T, seq(4, 8, 0.2))
# Colored histogram with border
hist(dat$SL, prob=T, seq(4, 8, 0.2),
     main="Histogram of Sepal.Length",
     xlab = "Sepal.Length",
     col="orange", border="green")

# Empirical cumulative distribution function
plot(ecdf(dat$SL), do.points=F, verticals=T,
     main="ECDF of Sepal.Length")

# Box plot
boxplot(dat$SL)           # Box plot
boxplot(dat$SL~dat$Sp)    # Box plots by species

# Dot plot
library(lattice)
dotplot(dat$SL~dat$Sp)

# Scatter plot
plot(dat$SL)          # One-way plot
plot(dat$SL, dat$PL)  # Two-way plot
# Plot all variables in the data set
# one against another in each sub-plot
plot(dat)   
# The following command plots a box plot
# since dat$Sp is a categorical/factor variable
plot(dat$Sp, dat$SL)

# Line plots
plot(dat$SL, type="l")
# Time plot
ts.plot(dat$SL)

# Q-Q plot
par(pty="s")      # Arrange a square region
qqnorm(dat$SL)    # Dot plot
qqline(dat$SL)    # Add a regression line

# Density curve
par(pty="m")      # Arrange a maximal region
# Plot of a specific density (normal)
x <- seq(-5,5,0.01)           # Set x-values
plot(x,dnorm(x,0,1),type="l")
# Plot an estimated density (kde)
plot(density(dat$SL))   # Default bandwidth
plot(density(dat$SL, bw=0.2), col="blue")

# Add the kde to the histogram
hist(dat$SL, prob=T, seq(4, 8, 0.2))
lines(density(dat$SL, bw=0.2), col="blue")
# Add (compared with) a normal density
x <- seq(3.5,8.5,0.01)
lines(x,dnorm(x, mean(dat$SL), sd(dat$SL)), col="red")

# 4.4 Statistical tests
# One sample t-tests
# H0: mu=0 vs H1: mu!=0
t.test(dat$SL)       
# H0: mu=6 vs H1: mu!=6
t.test(dat$SL, mu=6)
# H0: mu=6 vs H1: mu<6
t.test(dat$SL, mu=6, alternative = "less")

# Two samples t-tests
t.test(dat$SL, dat$SW)
t.test(dat$SL, dat$SW, mu=3)
t.test(dat$SL, dat$SW, mu=3, 
       alternative = "greater")
# Test same variance
var.test(dat$SL, dat$SW)               
var.test(dat$SL, dat$SW, ratio=3)               
var.test(dat$SL, dat$SW, ratio=3, 
         alternative = "greater")               
# Test means assuming equal variance
t.test(dat$SL, dat$SW, var.equal = T)  
t.test(dat$SL, dat$SW, var.equal = F)  

# Normality tests
# Shapiro-Wilk test
shapiro.test(dat$SL)  
# Kolmogorov-Smirnov test
ks.test(dat$SL, "pnorm", mean=mean(dat$SL),
        sd=sd(dat$SL))  
# Jarque-Bera Test
require(tseries)
jarque.bera.test(dat$SL)

# Kolmogorov-Smirnov test for other distribution
ks.test(dat$SL, "pt", df=4)  
# Two-sample Kolmogorov-Smirnov test
ks.test(dat$SL, dat$SW)  


############################################################

# Chapter 5. Advanced Computations, Functions, and Graphics

############################################################

# 5.1 For and while loops

# Define sequences X_i and Y_i using for loops
# Incorrect usage
for(i in 1:5) {x[i] <- 0.1*i; y[i] <- 2*i}
x; y
# Correct usage
x <- numeric(); y <- numeric()
for(i in 1:5) {x[i] <- 0.1*i; y[i] <- 2*i}
x; y

# Iteration using for loops
x <- 1; y <- 2       # Initial value
for (i in 1:100) {
  x <- sqrt(x*y)
  y <- (x+y)/2 
}
x; y

# Output sequential values of iterations
x <- numeric(100); y <- numeric(100)
x[1] <- 1; y[1] <- 2       # Initial value
for (i in 2:100) {
  x[i] <- sqrt(x[i-1]*y[i-1])
  y[i] <- (x[i]+y[i-1])/2 
}
x[1:15]
y[1:15]

# Recursion using for loops
# Generate 100 values of a 2nd order recursive sequence
z <- numeric(100);
z[1] <- 1; z[2] <- 3.2
for (i in 3:100) z[i] <- 0.5+0.8*z[i-1]-0.5*z[i-2]
z

# while statement to calculate z_n
z <- numeric(); z[1] <- 1; z[2] <- 3.2  # Initialization
i <- 2  # Count the number of recursions, not compulsory
# Distance/Difference between two consecutive values
dist <- abs(z[2]-z[1])            # Original difference
while (dist>1E-7) {
  i <- i+1                        # Update steps i
  z[i] <- 0.5+0.8*z[i-1]-0.5*z[i-2]
  dist <- abs(z[i]-z[i-1])        # Update difference
}
# Output required number of recursions and the final value
i; z[i]

# 5.2 Conditional executions

# IF-ELSE statements
rm(x); rm(y)
# if statement 1
x <- 8
if (x<9) a1 <- "x<9"
a1

# if statement 2
if (x<7) a2 <- "x<7" 
a2

# if statement 3
a3 <- character(1)
if (x<7) a3 <- "x<7"
a3

# if-else statement 1
if (x<7) b1 <- "x<7" else b1 <- "x>=7"
b1

# if-else statement 2, with multiple actions
if (x<9) { b2 = 1; b3 = 2} else { b2 = -1; b3 = -2 }
b2; b3

# if-else statement 3: 
# Incorrect use of line break(s)
if (x>9) { b4 = 1; b5 = 2} 
else { b4 = -1; b5 = -2 }
b4; b5
# Correct use
if (x>9) {
  b4 = 1; b5 = 2
} else {
  b4 = -1; b5 = -2
}
b4; b5

# 4: Chain of if-else statements:
marks <- 56
if (marks >= 80) {
  grade = "A" 
  } else if (marks >= 65) {
    grade = "B" 
    } else if (marks >= 50) {
      grade = "C"
      } else if (marks >= 40) {
        grade = "D" 
        } else grade = "F"
grade

# 5: 'ifelse' statement equivalent to `if-else` statement 1
ifelse(x<7, "x<7", "x>=7")
# Assignment the value to an R object
b6 <- ifelse(x<7, "x<7","x>=7")
b6

# 5.3. Defining your own functions

# All Built-in Objects
builtins()
builtin <- builtins(); View(builtin)

# Example 1: f(x,y)=x^3+y^3
sum1.cub <- function(x,y) x^3+y^3
sum1.cub(1,2)
sum2.cub <- function(x,y) {
  a <- x^3+y^3
  cat("The sum of cubes of", x, "and", y, "is", a)
}
sum2.cub(1,2)

# Example 2: transpose of matrices
trans.m <- function(m){
  # Transpose of matrix
  vm <- as.vector(m)
  tm <- matrix(vm, nrow = ncol(m), ncol = nrow(m), 
               byrow = TRUE)
  return(list(m,tm))
}
Mm <- matrix(1:18, nrow = 3, ncol = 6)
trans.m(Mm)

# Example 3: two sample test for difference in means
twomean.test <- function(x, y, alt) {
  n1  <- length(x); n2  <- length(y)
  mu1 <- mean(x);   mu2 <- mean(y)
  s1  <- var(x);    s2  <- var(y)
  s <- ((n1-1)*s1 + (n2-1)*s2)/(n1+n2-2)
  st.test <- (mu1 - mu2)/sqrt(s*(1/n1 + 1/n2))
  df.test <- n1+n2-2
  if (alt=="two.sided") pv.test <- 2-2*pt(abs(st.test), 
                                          df.test)
  if (alt=="less") pv.test <- pt(st.test, df.test)
  if (alt=="greater") pv.test <- 1-pt(st.test, df.test)
  paste("t =", st.test, ",",
        "df =", df.test, ",",
        "p-value =", pv.test, ",",
        "alternative =", alt)
}
A <- c( 79.98, 80.04, 80.02, 80.04, 80.03, 80.03, 80.04, 
        79.97, 80.05, 80.03, 80.02, 80.00, 80.02)
B <- c( 80.02, 79.94, 79.98, 79.97, 79.97, 80.03, 79.95, 
        79.97)
twomean.test(A, B, "less")
twomean.test(A, B, "greater")
twomean.test(A, B, "two.sided")

# Exercise: Function of approximating ln(1+x)
lnx <- function(x) {
  n <- 0
  fn <- 0              # Original value
  dist <- 1             # Original difference
  while (dist>1E-10) {
    n <- n+1                        # Update steps n
    fn0 <- fn                       # Value at (n-1)
    fn <- fn0 + (-1)^(n-1)*x^n/n    # Value at n
    dist <- abs(fn-fn0)             # Update difference
  }
  paste("n=", n, ",", "lnx(", 1+x, ")=", fn)
}
lnx(0.3)

# 5.4 Graphical procedures
# Help information
?plot

# Basic usages
setwd("C:/Teaching/R Workshop")
house2 <- read.table('house.txt',header=TRUE)
plot(house2$price)
plot(house2$lot, house2$price)
subf <- as.factor(house2$sub)
plot(subf, house2$price)
plot(house2)
plot(house2$price ~ house2$lot + house2$space + house2$age)

# Run the following commands one by one
yy <- log(co2[1:36])
xx <- 1:36
plot(y=yy,x=xx,type='l',col=2,lty=3,
     xlim=c(0,36),ylim=c(5.74,5.78),
     xlab='x-axis',ylab='y-axis',main='Demo of Plot()')
y2 <- log(co2[37:72])
lines(y=y2,x=xx,lty=2,col="blue")
points(y=y2,x=xx)
abline(h=5.76)
abline(v=c(10,30), col="blue")


########################################################

# Chapter 6. Linear Regression Models

########################################################

# Food expenditure data
setwd("C:/Teaching/R Workshop")
food <- read.csv("food.csv")
food1 <- food[1:198,]   # Remove missing values

# Scatter plot of food against total
plot(food1$TOTAL, food1$FOOD, 
     xlab = "Total", ylab = "Food", col = "blue")

#### 6.1 Simple LIM of food against total ####

# Least Squares Estimation (LSE)
food.fit <- lm(FOOD ~ TOTAL, data = food1)
summary(food.fit)

# Save fitted values and residuals
food1$fit <- food.fit$fitted.values
food1$res <- food.fit$residuals

# Define plot area as two rows and two columns
par(mfrow = c(2, 2))
# Scatter plot plus regression line
plot(food1$TOTAL, food1$FOOD, 
     xlab = "Total", ylab = "Food", col = "blue")
lines(food1$TOTAL, food1$fit, col = "red")
# Residual plots
plot(food1$res, food1$TOTAL)
hist(food1$res)
# Change back to the solo-figure view
par(mfrow = c(1, 1))

# Confidence intervals of coefficients
# All coefficients
confint.lm(food.fit)
# First coefficient
confint.lm(food.fit, 1)
# Second coefficient
confint.lm(food.fit, 2)
# Coefficient of a specific variable
confint.lm(food.fit, "TOTAL")
# Change confidence level
confint.lm(food.fit, level=0.9)

# Predicts and 95% confidence intervals
food.pc <- predict(food.fit, newdata = food, 
                   level = 0.95, 
                   interval = "confidence")
View(food.pc)

# Predicts and 95% prediction intervals
food.pp <- predict(food.fit, food, level = 0.95, 
                   interval = "prediction")
View(food.pp)

# Add predictions to data frame "food"
food$fit <- food.pc[,1]
food$CI_lower <- food.pc[,2]
food$CI_upper <- food.pc[,3]
food$PI_lower <- food.pp[,2]
food$PI_upper <- food.pp[,3]
View(food)

# Plots
plot(food$TOTAL, food$FOOD, xlab="TOTAL", ylab="FOOD")
lines(food$TOTAL, food$fit, type="l")
lines(food$TOTAL, food$CI_lower, type="l", col=2)
lines(food$TOTAL, food$CI_upper, type="l", col=2)
lines(food$TOTAL, food$PI_lower, type="l", col="blue")
lines(food$TOTAL, food$PI_upper, type="l", col="blue")

# An alternative package for OLSE
library(olsrr)
# OLSE
ols_regress(FOOD ~ TOTAL, data = food1)

# Regression Line
ols_plot_reg_line(food1$FOOD, food1$TOTAL)
# Actual vs Fitted Values Plot
ols_plot_obs_fit(food.fit)
# Residual vs Fitted Values Plot
ols_plot_resid_fit(food.fit)
# Residual histogram
ols_plot_resid_hist(food.fit)
# Residual Q-Q plot
ols_plot_resid_qq(food.fit)

#### 6.2. Multiple LIMs of house data ####

# House price data
house <- read.csv('house.csv')

# Model 0:
m0 <- lm(price ~ ., data = house)
summary(m0)

# Model 1: the full model
m1 <- lm(price ~ tax + lot + space + age, data = house)
summary(m1)
m1rr <- ols_regress(price~tax+lot+space+age, data=house)
summary(m1rr); m1rr

# ANOVA table by variables
anova(m1)

# ANOVA table when orders of variables are changed
anova(lm(price ~ lot + space + tax + age, data = house))

# Model 2: remove "age"
m2 <- lm(price ~ tax + lot + space, data = house)
m2rr <- ols_regress(price ~ tax + lot + space, data = house)
m2rr

# Model 3: remove "tax"
m3 <- lm(price ~ lot + space + age, data = house)
m3rr <- ols_regress(price ~ lot + space + age, data = house)
m3rr

# Model 4: further remove "age" and intercept
m4 <- lm(price ~ lot + space -1, data = house)
m4rr <- ols_regress(price ~ lot + space -1, data = house)
m4rr
anova(m4)

# F test: Model 1 against Model 2
F.val <- (739.492-727.98)/727.98*23; F.val
p.val <- 1-pf(F.val, 1, 23); p.val

# F test: Model 3 against Model 4
F.num <- (m4rr$ess-m3rr$ess)/(m4rr$error_df-m3rr$error_df)
F.den <- m3rr$ess/m3rr$error_df
F.val <- F.num/F.den
p.val <- 1-pf(F.val, m4rr$error_df-m3rr$error_df, 
              m3rr$error_df) 
F.val; p.val

# Define a function for general F test
F.test <- function(mf, mr){
  df.num <- mr$error_df - mf$error_df
  F.num <- (mr$ess  -mf$ess) / df.num
  df.den <- mf$error_df
  F.den <- mf$ess / df.den
  F.val <- F.num / F.den
  p.val <- 1-pf(F.val, df.num, df.den) 
  paste("F Statistic =", round(F.val, 4), ",",
        "p value =", round(p.val, 4)) }

# Apply the function
F.test(m1rr, m2rr)
F.test(m3rr, m4rr)

# Model/Residual diagnostic for Model 4
ols_plot_obs_fit(m4)
ols_plot_resid_fit(m4)
ols_plot_resid_hist(m4)
ols_plot_resid_qq(m4)

# Standardized coefficients
house.stb <- lm(scale(price) ~ scale(lot) +
                  + scale(space) -1, data = house)
coef(house.stb)

# Elasticity
house.els <- lm(log(price) ~ log(lot) +
                  + log(space) -1, data = house)
coef(house.els)

# Save fitted values
house$fit <- m4$fitted.values
View(house)

# Correlations of response to predictors
cor(house$price, house[,c(2,3,4,5)])
cor.test(house$price, house$tax)$p.value
cor.test(house$price, house$lot)$p.value
cor.test(house$price, house$space)$p.value
cor.test(house$price, house$age)$p.value

# Regression lines of response on each predictor
ols_plot_reg_line(house$price, house$tax)
ols_plot_reg_line(house$price, house$lot)
ols_plot_reg_line(house$price, house$space)
ols_plot_reg_line(house$price, house$age)

# Model 5: Add dummy variable for intercepts
m5 <- lm(price ~ tax + lot + space + age + sub, 
         data = house)
m5rr <- ols_regress(price ~ tax + lot + space 
                    + age + sub, data = house)
m5rr

# Model 6: Dummy variable for different price per space
m6 <- lm(price ~ tax + lot + space + sub:space 
         + age - 1, data = house)
m6rr <- ols_regress(price ~ tax + lot + space + sub:space
                    + age - 1, data = house)
# Equivalent commands
m6 <- lm(price ~ tax + lot + space + sub*space 
         + age - sub - 1, data = house)
m6rr <- ols_regress(price ~ tax + lot + space + sub*space
                    + age - sub - 1, data = house)
# Fit summary
summary(m6); m6rr


########################################################

# Appendix 1: Generate/Solve Sudoku Puzzles in R

########################################################

library(sudoku)
# Load a sudoku puzzle
setwd("C:/Teaching/R Workshop")
puzz <- readSudoku("Sudoku.txt")
# View the puzzle
View(puzz)
# Solve (and print out) the sudoku puzzle
sol <- solveSudoku(puzz, map=c(1:9,letters), print.it=TRUE)
# View the solution in Editor
View(sol)


############################################################

# Appendix 2:  Approximating pi as the area of unit circle

############################################################

# Cut the unit circle into parallel (to Y axis) pieces
# Approximate the area of each piece by that of a rectangle
# Add over the areas to approximate pi
pi.approx <- function(n) { # Define as a function
  h <- numeric(n)
  for (i in 1:n) {
    h[i] <- (sqrt(1-i^2/n^2)+sqrt(1-(i-1)^2/n^2))/2
  }
  pi.app <- 4*sum(h/n)
  pi.app
}
pi.approx(1000)
pi.approx(1000000)
