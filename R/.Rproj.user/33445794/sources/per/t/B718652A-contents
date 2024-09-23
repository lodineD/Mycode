library(spatstat)
library(RANN)
library(MASS)

set.seed(123)

# Number of simulations
num_sims <- 1000

# Store statistics from simulations
sim_stats <- numeric(num_sims)

# Perform simulations
for (i in 1:num_sims) {
  x <- runif(n)
  y <- runif(n)
  myppp <- ppp(x, y)
  nn <- nndlist(myppp)
  sim_stats[i] <- 2 * pi * lambda * sum(nn^2)
}

# Fit a distribution to the simulated statistics (e.g., normal)
fit <- fitdistr(sim_stats, "norm")

# Plot the histogram of simulated statistics
hist(sim_stats, probability = TRUE, col = "grey", border = "white")
curve(fit$estimate["mean"] + fit$estimate["sd"] * qnorm(x), col = "blue", add = TRUE)
