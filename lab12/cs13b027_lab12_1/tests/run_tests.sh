#
# CS2110 Testbench
# Runs tests

TEST_DIR=tests
TEST_COUNT=4
PROG=lcs
ARGS=

j=0
for i in `seq 1 $TEST_COUNT`; do
    echo -n "Running Test $i... "
    inp="in-$i";
    outp="out-$i";
    outp_="out-${i}_";
    ./$PROG $ARGS < $TEST_DIR/$inp > $TEST_DIR/$outp_;
    diff -bBq $TEST_DIR/$outp $TEST_DIR/$outp_ > /dev/null;
    if [[ $? == 0 ]] ; then
        echo "Passed."
        j=$((j+1))
    else
        echo "Failed."
    fi
done;

echo "Done ($j/4) passed."
