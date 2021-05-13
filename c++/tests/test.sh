#!/bin/bash
echo "Testing: "
g++ test_structs.cpp -o test_structs && ./test_structs > test1.out
g++ test_structs_template.cpp -o test_structs_template && ./test_structs_template > test2.out
g++ test_alg.cpp -o test_alg && ./test_alg > test3.out

diff test1.out test_structs.out > diff.out
diff test2.out test_structs_template.out >> diff.out
diff test3.out test_alg.out >> diff.out

if [ -s diff.out ] # test if diff is empty
then
    cat diff.out # print
    exit 1 # test failed
fi

