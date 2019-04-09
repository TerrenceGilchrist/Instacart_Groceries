# !/bin/bash



# Test Suggested by Insight

# compiler	         g++
# source code	         /src/Groceries.cpp
# input		         /test_suite/test_1/input/products.csv
# input		         /test_suite/test_1/input/order_products.csv
# signal about test	    test
# input folder	        /test_suite/test_1/input/
# output folder	        /test_suite/test_1/output/

g++ /src/Groceries.cpp /test_suite/test_1/input/products.csv /test_suite/test_1/input/order_products.csv test /test_suite/test_1/input/ /test_suite/test_1/test_1/output/



# compiler		       g++
# source code	          /src/Groceries.cpp
# optimizer	         -O2
# counter initiation	  200824
# input		         /input/products.csv
# input		         /input/order_products__prior.csv
# signal about test	   test
# input folder	        /input/
# output folder	        /test_suite/personal_test/output/

g++ /src/Groceries.cpp -O2 200824 /input/products.csv /input/order_products__prior.csv test /input/ /test_suite/personal_test/output/
