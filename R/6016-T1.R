x = c(1, 2, -1)
y = c(0.4, 5, 8)
A = matrix(
  c(4, -3, 1, 0.5, 2, 2, 6, 7, -2),
  byrow = T,
  nrow = 3,
  ncol = 3
)
B = matrix(c(-1, 2, 1, -2, 3, 1),
           byrow = T,
           nrow = 3,
           ncol = 2)
z = 2.3 * x - y / 7
z
print(z, digits = 2)


# 矩阵相乘
A %*% A
# 值相乘
A * A
library(matlib)
inv(A)*B
