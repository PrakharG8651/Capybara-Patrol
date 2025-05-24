/**
 * gen-array-with-opt   -test-count <num>
 *                      -sum-n <num>
 *                      [-min-n <num>]
 *                      [-min-value <num>] [-max-value <num>]
 *                      [-value-bias <num>]
 * 
 * Generate a test with `test-count` test cases, each test case is an
 * array. The sum of lengths of all arrays will equal `sum-n`.
 * 
 * Arguments:
 * -test-count: specify the number of test cases. Required.
 * -sum-n: specify the sum of array lengths over all test cases. Required.
 * -min-n: specify the minimum array length for all test cases. Default: 1.
 * -min-value: specify the minimum value for the array element. Default: 1.
 * -max-value: specify the maximum value for the array element. Default: 10^9.
 * -value-bias: specify the bias for generating the value. The bigger the
 *  _positive_ value-bias, the closer the element to max-value. The smaller the
 *  _negative_ value-bias, the closer the element to min-value. See rnd.wnext()
 *  function. Default: 0 (no bias).
 */

#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    // Required arguments
    int test_count = opt<int>("test-count");
    int sum_n = opt<int>("sum-n");

    // Optional arguments with defaults
    int min_n = opt<int>("min-n", 1);
    int min_value = opt<int>("min-value", 20);
    int max_value = opt<int>("max-value", int(1e9));
    int value_bias = opt<int>("value-bias", 20);

    // Partition the total sum_n into test_count array sizes, each at least min_n
    vector<int> n_list = rnd.partition(test_count, sum_n, min_n);

    // Output begins
    println(test_count);
    for (int test_case = 0; test_case < test_count; ++test_case) {
        int n = n_list[test_case];
        println(n);

        // Generate the array values
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = rnd.wnext(min_value, max_value, value_bias);
        }
        println(arr); // space-separated array
    }
}
