#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#define TEST_EQUAL(lhs, rhs) \
    do { \
        if ((lhs) != (rhs)) { \
            std::cerr << "Test failed: " #lhs " != " #rhs \
                      << "\nFile: " << __FILE__ \
                      << "\nLine: " << __LINE__ \
                      << "\nValues: " << (lhs) << " != " << (rhs) << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
    } while (0)

#define CASE_TITLE() \
    do { \
        std::cout << "################## " \
                    << __FUNCTION__ \
                    << " ##################" \
                    << std::endl; \
    } while (0)

#endif  // TEST_COMMON_H