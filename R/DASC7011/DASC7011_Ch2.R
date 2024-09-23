################################################
################ Chapter 2: MME ################
################################################

###### Example 2.1: Sample moments ######

# Generate samples
n <- 100
set.seed(7011)
X <- rnorm(n, 5, 2)
Y <- rt(n,4)

# Sample moments by built-in functions
mean(X)
var(X)
sd(X)
cov(X,Y)
cor(X,Y)
require(e1071)
skewness(X)
kurtosis(X)

# Sample moments by self-defined functions
mean.x <- sum(X)/n; mean.x
var.x <- sum((X-mean.x)^2)/(n-1); var.x
sd.x <- sqrt(var.x); sd.x
mean.y <- sum(Y)/n
var.y <- sum((Y-mean.y)^2)/(n-1)
sd.y <- sqrt(var.y)
cov.xy <- sum((X-mean.x)*(Y-mean.y))/(n-1); cov.xy
cor.xy <- cov.xy/sd.x/sd.y; cor.xy
skew.x <- sum((X-mean.x)^3)/n/sd.x^3; skew.x
kurt.x <- sum((X-mean.x)^4)/n/sd.x^4-3; kurt.x


###### Example 2.6: Inferences on one mean ######

# Generate the sample
n <- 100
mu <- 5
sigma <- 2
set.seed(7011)
x <- rnorm(n, mu, sigma)
# Sample mean and sample standard deviation
x.mean <- mean(x)
x.sd <- sd(x)

# (i) Assume sigma=2 is known
# 95% CI for mu
ci1.low <- x.mean-qnorm(0.975)*sigma/sqrt(n)
ci1.up <- x.mean+qnorm(0.975)*sigma/sqrt(n)
ci1 <- c(ci1.low, ci1.up); ci1
# Test mu=4 vs mu=!4 
mu0 <- 4
z1 <- (x.mean-mu0)/sigma*sqrt(n); z1
p1 <- 2*pnorm(-z1,0,1); p1

# (ii) Manual calculation assume sigma is unknown
# 95% CI for mu when sigma is unknown
ci2.low <- x.mean-qt(0.975, df=n-1)*x.sd/sqrt(n)
ci2.up <- x.mean+qt(0.975, df=n-1)*x.sd/sqrt(n)
ci2 <- c(ci2.low, ci2.up); ci2
# Test mu=4 vs mu=!4
t1 <- (x.mean-mu0)/x.sd*sqrt(n); t1
p2 <- 2*pt(-t1,n-1); p2

# (iii) Using t.test()
t.test(x, alternative = "two.sided", mu=mu0)
t.test(x, alternative = "less", mu=mu0)
t.test(x, alternative = "greater", mu=mu0)


###### Example 2.7: Inferences on variances ######
# Generate samples from Y~N(0,6)
n2 <- 200
set.seed(2024)
y <- rnorm(n2, 0, sqrt(6))

# (i) Test sigma(x)=2
require(EnvStats)
varTest(x, alternative = "two.sided", sigma.squared = 4)

# (ii) Test sigma(x) >= sigma(y)
var.test(x, y, ratio = 1, alternative = "less")


###### Example 2.8: Inferences on two means ######
# T-test assuming equal variance
t.test(x, y, alternative = "two.sided", var.equal = T)

# Welch's T-test
t.test(x, y, alternative = "two.sided", var.equal = F)

# Paired samples T-test
set.seed(7011)
X <- rt(n,5)
Y <- runif(n,-0.8,1)
cor(X,Y)
t.test(X, Y, alternative = "two.sided", paired = T)


###### Example 2.9: Binomial test ######
# Generating the random sample
n <- 50
set.seed(7011)
X <- rbinom(n, 1, 0.4)
Y <- sum(X)         # Number of successes
X1 <- c(Y, n-Y)     # Numbers of successes/failures
p0 <- 0.5

# Binomial tests
binom.test(x = Y, n = n, p = p0)
binom.test(x = X1, p = p0)

# Approximate Z-test
Z <- (mean(X)-p0)/sqrt(p0*(1-p0)/n); Z
p.val <- pnorm(Z)*2; p.val
# Approximate and analytic CI
c <- qnorm(0.025)^2/n
p.hat <- mean(X)
p1 <- (2*p.hat+c-sqrt(c^2+4*c*p.hat*(1-p.hat)))/(2*(1+c))
p2 <- (2*p.hat+c+sqrt(c^2+4*c*p.hat*(1-p.hat)))/(2*(1+c))
c(p1, p2)

###### Example 2.10: Jarque-Bera test ######
require(tseries)
x <- rnorm(100, 0, 1)
jarque.bera.test(x)
y <- rcauchy(100, 0, 1)
jarque.bera.test(y)


