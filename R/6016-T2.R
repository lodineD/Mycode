#1.a
X = c(1,3,4,7,9)
Y = c(0.5,3.5,2.5,4,3)
ppp=data.frame(X,Y)
#1.b
Marks = c(0.5,1,1.5,4,5)
ppp$Marks=Marks
#1.c
Marks = c(1,2,1,2,1)
ppp$Marks=Marks
#1.d
install.packages("units")
library("units")
units(ppp$X)='m'
ppp$X
units(ppp$Y)='m'
ppp$Y
#1.e
units(ppp$X) = '42cm'
units(ppp$Y) = '42cm'
#1.f
xx = c(0,0,5,10,10)
yy = c(0,2,5,4,0)
plot(xx,yy)
polygon(xx,yy)
points(ppp$X,ppp$Y)
#1.g
xx = c(0,0,5,5)
yy = c(0,2,3,0)
plot(xx,yy)
polygon(xx,yy)
points(c(1,4),c(0.5,2.5))
#1.h
install.packages("splancs")
library("splancs")
library("sp")
poly1 = cbind(xx,yy)
csr_data = csr(poly1,10)
points(csr_data)

#2.a
q11 = read.csv("q11.csv",header=T)
plot(q11$Var1,q11$Var2)
#2.b
abline(v=0.525,h=0.525)
#2.c
((100-361*0.525^2)^2/(0.525^2)+2*(90-361*0.525*0.475)^2/(0.525*0.475)+(81-361*0.475^2)^2/(0.475^2))/361








data(cardiff)
nsim  =  29
emp.Ghat = Ghat(as.points(cardiff), seq(0,30,1))
av.Ghat = numeric(length(emp.Ghat))
U.Ghat = numeric(length(emp.Ghat))
L.Ghat = numeric(length(emp.Ghat))
U.Ghat = -99999
L.Ghat = 99999
for(i in 1:nsim) {
  S.Ghat = Ghat(csr(cardiff$poly, length(cardiff$x)), seq(0,30,1))
  av.Ghat = av.Ghat + S.Ghat
  L.Ghat = pmin(S.Ghat, L.Ghat)
  U.Ghat = pmax(S.Ghat, U.Ghat)
}
av.Ghat = av.Ghat/nsim
plot(av.Ghat, emp.Ghat, type="l", xlim=c(0,1), ylim=c(0,1), 
     xlab="Simulated average G", ylab="Empirical G")
lines(c(0,1),c(0,1),lty=2)
lines(U.Ghat,emp.Ghat,lty=3)
lines(L.Ghat,emp.Ghat,lty=3)