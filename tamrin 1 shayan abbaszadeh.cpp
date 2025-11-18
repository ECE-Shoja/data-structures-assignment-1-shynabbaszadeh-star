#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> opStack;
    stringstream output;
    for (size_t i = 0; i < infix.length(); ++i) {
        char ch = infix[i];

        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
                output << infix[i];
                ++i;
            }
            output << ' ';
            --i;
        }
        else if (ch == '(') {
            opStack.push(ch);
        }
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                output << opStack.top() << ' ';
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch)) {
                output << opStack.top() << ' ';
                opStack.pop();
            }
            opStack.push(ch);
        }
    }

    while (!opStack.empty()) {
        output << opStack.top() << ' ';
        opStack.pop();
    }

    return output.str();
}

double evaluatePostfix(const string& postfix) {
    stack<double> valStack;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            valStack.push(stod(token));
        }
        else {
            double b = valStack.top(); valStack.pop();
            double a = valStack.top(); valStack.pop();
            if (token == "+") valStack.push(a + b);
            else if (token == "-") valStack.push(a - b);
            else if (token == "*") valStack.push(a * b);
            else if (token == "/") valStack.push(a / b);
        }
    }

    return valStack.top();
}

int main() {
    string expression;
    cout << "enter the number:";
    getline(cin, expression);

    string postfix = infixToPostfix(expression);
    double result = evaluatePostfix(postfix);

    cout << "result:" << result << endl;
    return 0;
}