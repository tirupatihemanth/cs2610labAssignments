#
# CS2110 Testbench
# Runs tests

TEST_DIR=tests
TEST_COUNT=4
PROG=continued-fractions
ARGS=

j=0
echo "Tests for $PROG"
for i in `seq 1 $TEST_COUNT`; do
    echo -n "Running Test $i... "
    inp="in-1-$i";
    outp="out-1-$i";
    outp_="out-1-${i}_";
    ./$PROG $ARGS < $TEST_DIR/$inp > $TEST_DIR/$outp_;
    # Parse a float
    v=$(echo "1 - `cat $TEST_DIR/$outp`/`cat $TEST_DIR/$outp_` < 0.01" | bc -l)
    if [[ $v == 1 ]] ; then
        echo "Passed."
        j=$((j+1))
    else
        echo "Failed."
    fi
done;
echo "Done ($j/$i) passed."
echo
echo

TEST_COUNT=5
PROG=pi
ARGS=

echo "Tests for $PROG"
j=0
for i in `seq 1 $TEST_COUNT`; do
    echo "Running Test $i... "
    inp="in-2-$i";
    outp="out-2-$i";
    outp_="out-2-${i}_";
    ./$PROG $ARGS < $TEST_DIR/$inp > $TEST_DIR/$outp_;
    # Parse a float
    cat $TEST_DIR/$outp $TEST_DIR/$outp_;
done;
echo "Done."
