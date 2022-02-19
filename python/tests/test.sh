#!/bin/bash
echo "Testing Python: "
python3 algo.test.py > test1.out
python3 sort.test.py > test2.out
python3 structs.test.py > test3.out

diff test1.out test_alg.out > diff.out
diff test2.out test_sort.out >> diff.out
diff test3.out test_structs.out >> diff.out

if [ -s diff.out ] # test if diff is empty
then
    cat diff.out # print
    exit 1 # test failed
fi

