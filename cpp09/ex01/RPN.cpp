#include "RPN.hpp"

#include <sstream>
#include <stdexcept>
#include <iostream>

static bool isOperator(const std::string& token) {
	return (token.size() == 1 && (token[0] == '+' || token[0] == '-'
		|| token[0] == '*' || token[0] == '/'));
}

static int applyOperator(char op, int a, int b) {
	switch (op) {
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw (std::runtime_error("Error: division by zero impossible"));
			return (a / b);
		default:
			throw (std::runtime_error("Error: not a valid operator"));
	}
}

static int parseNumber(const std::string& token) {
	if (token.find_first_not_of("0123456789") != std::string::npos || token.size() > 1)
		throw (std::runtime_error("Error: not a valid number"));
	return (token[0] - '0');
}

void RPN::doTheThing(const std::string& input)
{
    std::istringstream iss(input);
    std::stack<int> stack;
    std::string token;
	int a;
	int b;
    while (iss >> token)
	{
        if (isOperator(token))
		{
            if (stack.size() < 2)
                throw (std::runtime_error("Error: stack too small"));
            b = stack.top();
			stack.pop();
            a = stack.top();
			stack.pop();
            stack.push(applyOperator(token[0], a, b));
        }
		else
            stack.push(parseNumber(token));
    }
    if (stack.size() != 1)
        throw (std::runtime_error("Error: need more tokens to finish RPN"));
	return (std::cout << stack.top() << std::endl, (void)0);
}
