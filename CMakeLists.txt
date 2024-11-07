cmake_minimum_required(VERSION 3.29)
project(UOC20241 C)

set(CMAKE_C_STANDARD 11)

add_executable(UOC20241
        src/main.c
        UOCTaxation/src/api.c
        UOCTaxation/src/csv.c
        UOCTaxation/src/date.c
        UOCTaxation/src/landlord.c
        UOCTaxation/src/rental_incomes.c
        UOCTaxation/src/tenant.c
        test/src/test.c
        test/src/test_pr1.c
        test/src/test_suite.c)
