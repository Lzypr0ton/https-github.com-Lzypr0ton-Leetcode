class Solution {
public:
    // Entry point for the solution that calls dfs() method with the input expression.
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }

private:
    // A memoization map to store previously calculated results for subexpressions.
    unordered_map<string, vector<int>> memo;

    // Recursive function to compute all possible results from the input expression.
    vector<int> dfs(const string& exp) {
        // If the result of this subexpression is already computed, return it.
        if (memo.count(exp)) return memo[exp];
      
        vector<int> results;
      
        // Check if the expression is a simple number.
        if(isNumber(exp)) {
            results.push_back(stoi(exp));
            return results;
        }
      
        int n = exp.size();
        // Iterate over each character of the expression.
        for (int i = 0; i < n; ++i) {
            char c = exp[i];
            // Check if the current character is an operator.
            if (c == '-' || c == '+' || c == '*') {
                // Recursively solve subexpression to the left of the operator.
                vector<int> leftResults = dfs(exp.substr(0, i));
                // Recursively solve subexpression to the right of the operator.
                vector<int> rightResults = dfs(exp.substr(i + 1));
              
                // Combine the results from both subexpressions based on the operator.
                for (int a : leftResults) {
                    for (int b : rightResults) {
                        if (c == '-')
                            results.push_back(a - b);
                        else if (c == '+')
                            results.push_back(a + b);
                        else // c == '*'
                            results.push_back(a * b);
                    }
                }
            }
        }
      
        // Store the computed results in the memoization map before returning.
        memo[exp] = results;
        return results;
    }

    // Helper function to determine if a given string is a number.
    bool isNumber(const string& str) {
        return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
    }
};