mydata = function(type) {
  switch(
    type,
    long = format(Sys.time(), "%A %B %D %Y"),
    short = format(Sys.time(), "%m-%d-%Y"),
    cat = format(type, "is not recoginized\n")
  )
  
}

mydata("short")

# return函数要加括号
sum = function(num){
  x = 0
  for (i in 1:num)
  {
    x = x+i
  }
  return (x)
}

sum(3)
