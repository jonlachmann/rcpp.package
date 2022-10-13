# rcpp.package
An R package that just contains a single Rcpp function doing addition of two numbers. The idea is to use this as a base for learning how to create R packages with functions implemented in C++ using Rcpp.

# Usage
- Clone the git repository (using git clone or just download the repo on github).
- Open the folder using RStudio or PyCharm and run ```devtools::document()```.
  - This generates the needed files ```R/RcppExports.R``` and ```src/RcppExports.cpp```
  - Other files are also generated, namely ```addition.o```, ```rcpp.package.so``` and ```RcppExports.o```. These are specific to the system where the package is built (i.e. OSX, Windows, Linux) and should not be included in the code that is saved on e.g. github.
- To build and install the package, simply run ```pack <- devtools::build(); install.packages(pack)```.
- You can now load the package in R using ```library(rcpp.package)```. This also exposes the example function ```addition(a, b)``` which simply adds two numbers and returns the result.

# Adding Rcpp functions
- Rcpp functions are stored in ```.cpp``` files in the ```src``` folder. Create a new file in that folder, making sure the file ending is ```.cpp```.
- Begin the file with the following lines
```
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
return_type my_function(argument_1_type argument_1) {
  // Your code here
}
```
- An explanation of what we see in the code above:
  - The first line adds the necessary header file ```Rcpp.h``` so we can use Rcpp functions in our C++ code.
  - The second line is optional, it lets us use functions from Rcpp without writing ```Rcpp::Rcpp_function()```.
  - C++ comments are marked with ```//```, writing ```// [[Rcpp::export]]``` lets devtools know that it should expose the function below to be used from R.
  - Finally we have the function body. Note C++ is a strongly typed language, meaning that every variable must be preceded by the type it has.
- When you are happy with your function, run ```devtools::document()``` to generate the files ```R/RcppExports.R``` and ```src/RcppExports.cpp```.
- _DO NOT_ edit the ```RcppExports``` files manually, it is just unneccesary work.
