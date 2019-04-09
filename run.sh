# !/bin/bash

# compiler	         g++
# source code	        /src/Groceries.cpp
# optimizer	        -O2
# input		        /input/products.csv
# input		        /input/order_products__prior.csv
# input folder	        /input/
# output folder	        /output/

g++ /src/Groceries.cpp -O2 /input/products.csv /input/order_products__prior.csv /input/ /output/
