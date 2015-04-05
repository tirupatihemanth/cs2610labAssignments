#
# CS2110 Testbench
# Runs tests

TEST_DIR=tests
TEST_COUNT=8
PROG=main
ARGS=

j=0
for i in `seq 1 $TEST_COUNT`; do
    echo -n "Running Test $i... "
    inp="in-1-$i";
    outp="out-1-$i";
    outp_="out-1-${i}_";
    ./$PROG $ARGS < $TEST_DIR/$inp > $TEST_DIR/$outp_;
    diff -bBq $TEST_DIR/$outp $TEST_DIR/$outp_ > /dev/null;
    if [[ $? == 0 ]] ; then
        echo "Passed."
        j=$((j+1))
    else
        echo "Failed."
    fi
done;
echo "Done ($j/$i) passed."

TEST_COUNT=4
PROG=factorial
ARGS=

j=0
for i in `seq 1 $TEST_COUNT`; do
    echo -n "Running Test $i... "
    inp="in-2-$i";
    outp="out-2-$i";
    outp_="out-2-${i}_";
    ./$PROG $ARGS < $TEST_DIR/$inp > $TEST_DIR/$outp_;
    diff -bBq $TEST_DIR/$outp $TEST_DIR/$outp_ > /dev/null;
    if [[ $? == 0 ]] ; then
        echo "Passed."
        j=$((j+1))
    else
        echo "Failed."
    fi
done;
echo "Done ($j/$i) passed."
