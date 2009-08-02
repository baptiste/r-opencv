#.First.lib <- function(lib,pkg) {
#  library.dynam("ropencv", pkg,lib)
#}
#
#.onLoad <- function(lib, pkg) {
#  library.dynam("ropencv", pkg,lib)
#}
#
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
  stopifnot(file.exists(file))
  ## expand path
  file <- path.expand(file)
  .C("showImage", file)
}
