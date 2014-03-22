conv <- function(a, b)
       .C("convolve",
          as.double(a),
          as.integer(length(a)),
          as.double(b),
          as.integer(length(b)),
          ab = double(length(a) + length(b) - 1))$ab

showImage <- function(file) {
  file <- as.character(file)[1]
  ## check for existence
  if(!file.exists(file))
      stop(file, "not found")
  ## expand path
  file <- path.expand(file)
  a <- .Call("loadImage", file)
  cat("SHOWING...\n")
  .Call("showImage", a)
  return(a)
}
