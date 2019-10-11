EXEC=$1
TMP_OUT=./build/$2

for i in {1..14..1}; do
  testname=$(printf "%02d" $i)
  $EXEC < ./tests/$testname.in > $TMP_OUT
  if ! diff -qwB ./tests/$testname.out $TMP_OUT &>/dev/null; then
    diff -ywB ./tests/$testname.out $TMP_OUT > ./build/diff_logs_$i
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done
