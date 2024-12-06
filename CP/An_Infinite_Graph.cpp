#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// Function to generate primes up to a certain limit using the Sieve of Eratosthenes
vector<int> generate_primes(int limit) {
    vector<bool> sieve(limit + 1, true);
    sieve[0] = sieve[1] = false;  // 0 and 1 are not prime
    for (int i = 2; i * i <= limit; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Optimized DP function to find the minimum number of primes needed to form the target sum
pair<int, vector<int>> min_indices_to_target_sum(const vector<int>& primes, int target) {
    // Initialize DP array where dp[i] represents the minimum number of elements to form sum i
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;  // No elements needed to form sum 0

    // Array to backtrack the prime number used to form the sum
    vector<int> last_prime_used(target + 1, -1);

    // DP iteration: for each prime number, update the DP table for all possible sums
    // from the prime number to the target sum
    for (int num : primes) {
        for (int sum_val = num; sum_val <= target; sum_val++) {
            if (dp[sum_val - num] + 1 < dp[sum_val]) {
                dp[sum_val] = dp[sum_val - num] + 1;
                last_prime_used[sum_val] = num;  // Record the prime number used for this sum
            }
        }
    }

    // If dp[target] is still INT_MAX, it means the target sum is not achievable
    if (dp[target] == INT_MAX) {
        return {0, {}};  // Return 0 and empty list if no solution is found
    }

    // Backtrack to find the primes used to form the target sum
    vector<int> result_indices;
    int remaining_sum = target;

    // While there is a remaining sum, keep subtracting the primes used
    while (remaining_sum > 0) {
        int prime_used = last_prime_used[remaining_sum];
        if (prime_used == -1) {
            return {0, {}};  // This should never happen if the target sum is achievable
        }

        // Find the index of prime_used in the primes list and store it
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] == prime_used) {
                result_indices.push_back(i);  // Store the index of the used prime
                break;
            }
        }

        remaining_sum -= prime_used;  // Subtract the prime used from the remaining sum
    }

    return {dp[target], result_indices};  // Return the result
}

int main() {
    int target = 42;  // Test case with target sum 42
    vector<int> primes = generate_primes(target);  // Generate primes up to target sum

    auto result = min_indices_to_target_sum(primes, target);

    if (result.first == 0) {
        cout << "No solution found." << endl;
    } else {
        cout << "Minimum number of elements: " << result.first << endl;
        cout << "Indices of elements used: ";
        for (int idx : result.second) {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}
