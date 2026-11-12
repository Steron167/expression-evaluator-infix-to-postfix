#include <iostream>
#include <string>

using namespace std;

// Simple array used as a stack to store operators (+, -, *, /) during conversion
char charStack[100];
int charTop = -1;

// Push a character onto the character stack
void pushChar(char c) {
    charTop++;
    charStack[charTop] = c;
}

// Pop a character from the character stack
char popChar() {
    char c = charStack[charTop];
    charTop--;
    return c;
}

// Simple array used as a stack to store numbers during evaluation
int intStack[100];
int intTop = -1;

// Push an integer onto the number stack
void pushInt(int val) {
    intTop++;
    intStack[intTop] = val;
}

// Pop an integer from the number stack
int popInt() {
    int val = intStack[intTop];
    intTop--;
    return val;
}

// Function to check the priority (precedence) of math operators
int getPriority(char op) {
    if (op == '*' || op == '/') {
        return 2; 
    }
    if (op == '+' || op == '-') { 
        return 1; 
    }
    return 0; 
}

// Function to convert an Infix expression into a Postfix expression
string convertToPostfix(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Skip empty spaces if the user typed any
        if (ch == ' ') {
            continue;
        }

        // Case 1: If the character is a number (0 to 9), add it directly to postfix string
        if (ch >= '0' && ch <= '9') {
            postfix = postfix + ch;
        }
        // Case 2: If it is an opening bracket '(', push it onto the stack
        else if (ch == '(') {
            pushChar(ch);
        }
        // Case 3: If it is a closing bracket ')', pop operators until '(' is found
        else if (ch == ')') {
            while (charTop != -1 && charStack[charTop] != '(') {
                postfix = postfix + popChar();
            }
            popChar(); // Remove the '(' from the stack as well
        }
        // Case 4: If it is an operator (+, -, *, /)
        else {
            while (charTop != -1 && getPriority(charStack[charTop]) >= getPriority(ch)) {
                postfix = postfix + popChar();
            }
            pushChar(ch);
        }
    }

    // Pop any remaining operators left inside the stack
    while (charTop != -1) {
        postfix = postfix + popChar();
    }

    return postfix;
}

// Function to calculate the final answer from the Postfix expression
int evaluatePostfix(string postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        // If the character is a number, convert it from char to int and push to stack
        if (ch >= '0' && ch <= '9') {
            int num = ch - '0'; // Subtracting '0' converts character digit to actual integer
            pushInt(num);
        }
        // If the character is an operator, pop two numbers and apply the math operation
        else {
            int val2 = popInt(); // Top number is the second operand
            int val1 = popInt(); // Next number is the first operand

            if (ch == '+') {
                pushInt(val1 + val2);
            } else if (ch == '-') {
                pushInt(val1 - val2);
            } else if (ch == '*') {
                pushInt(val1 * val2);
            } else if (ch == '/') {
                pushInt(val1 / val2);
            }
        }
    }

    // The last remaining number in the stack is our final answer
    return popInt();
}

int main() {
    string infixExpression;

    cout << "=============================================" << endl;
    cout << "  INFIX TO POSTFIX CONVERTER AND EVALUATOR   " << endl;
    cout << "=============================================" << endl;
    cout << "Note: Enter single-digit numbers (0-9) and" << endl;
    cout << "basic operators (+, -, *, /) with brackets." << endl;
    cout << "Example: (5+3)*2 or 8+(6/2)-1" << endl;
    cout << "---------------------------------------------" << endl;

    cout << "Enter Infix Expression: ";
    cin >> infixExpression;

    // Step 1: Convert Infix to Postfix
    string postfixExpression = convertToPostfix(infixExpression);
    cout << "Converted Postfix Expression: " << postfixExpression << endl;

    // Step 2: Evaluate Postfix Expression
    int finalAnswer = evaluatePostfix(postfixExpression);
    cout << "Final Evaluated Answer: " << finalAnswer << endl;

    cout << "=============================================" << endl;

    return 0;
}