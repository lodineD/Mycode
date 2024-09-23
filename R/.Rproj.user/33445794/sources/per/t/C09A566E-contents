library(spatstat)
library(RANN)

# Set the seed for reproducibility
set.seed(123)

# Number of locations
n <- 50

# Generate random locations in a unit square
x <- runif(n)
y <- runif(n)

# Create a point pattern object
myppp <- ppp(x, y)

# Compute the nearest-neighbor distances
nn <- nndist(myppp)

# Calculate the intensity lambda (number of points per unit area)
lambda <- n / 1  # Area of the unit square

# Compute the statistic
statistic <- 2 * pi * lambda * sum(nn^2)

# Print the statistic
print(statistic)
