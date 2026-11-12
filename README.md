# Expression Evaluator and Infix-to-Postfix Converter

A console-based C++ application that converts arithmetic infix expressions into postfix notation (Reverse Polish Notation) and evaluates the resulting postfix expression using array-based stacks.

## Project Details

- **Institution:** Sanjivani University, School of Engineering and Technology
- **Department:** Computer Science & Engineering
- **Program:** Career Craft Academy powered by HCL Tech
- **Trainer:** Mr. Tilak
- **Submission Date:** 03/11/2026

### Team Members

| Name | Roll Number |
| :--- | :--- |
| Yash Wani | 2126UCEM1136 |
| Aaditya Kalavadekar | 2126UCEM1050 |
| Krishna Kadu | 2126UCEM1060 |

## Repository Contents

- `(by Krishna kadu)-Expression Evaluator and Infix-to-Postfix Converter.cpp` - C++ source implementation of the infix-to-postfix converter and postfix evaluator.
- `(by Krishna kadu):Expression Evaluator and Infix-to-Postfix Converter.exe` - Pre-compiled 32-bit Windows console executable (PE32 Intel 80386).
- `Expression_Evaluation_Infix_to_Postfix_Project_Report.docx` - Complete project report detailing problem statement, requirements, data structures, design, test cases, and future scope.

## How It Works

The program uses two fixed-size global array stacks (capacity `100`):

1. **Character Stack (`charStack`)**: Managed by `pushChar()` and `popChar()`, used during infix-to-postfix conversion to hold operators and opening parentheses `(`.
2. **Integer Stack (`intStack`)**: Managed by `pushInt()` and `popInt()`, used during postfix evaluation to store operands and intermediate integer results.

### Core Functions

- `getPriority(char op)` - Returns precedence `2` for `*` and `/`, `1` for `+` and `-`, and `0` otherwise.
- `convertToPostfix(string infix)` - Scans the infix string left-to-right, outputs digits (`0`-`9`) directly, handles parentheses `(` and `)`, and pops/pushes operators according to precedence.
- `evaluatePostfix(string postfix)` - Scans the postfix string left-to-right, pushes digit values onto `intStack`, pops two operands (`val2`, then `val1`) for each operator, computes `val1 <op> val2`, and pushes the result back.
- `main()` - Displays instructions, reads an infix expression from standard input, prints the converted postfix expression, and prints the evaluated integer result.

### Complexity

- **Time Complexity:** `O(n)` for both conversion and evaluation, where `n` is the expression length.
- **Space Complexity:** `O(n)` auxiliary stack space (bounded by the fixed array capacity of `100`).

## Building and Running

### Compile from Source (macOS / Linux / Windows with g++)

```bash
g++ -std=c++17 "(by Krishna kadu)-Expression Evaluator and Infix-to-Postfix Converter.cpp" -o evaluator
./evaluator
```

### Example Session

```text
=============================================
  INFIX TO POSTFIX CONVERTER AND EVALUATOR   
=============================================
Note: Enter single-digit numbers (0-9) and
basic operators (+, -, *, /) with brackets.
Example: (5+3)*2 or 8+(6/2)-1
---------------------------------------------
Enter Infix Expression: (5+3)*2
Converted Postfix Expression: 53+2*
Final Evaluated Answer: 16
=============================================
```

## Current Scope and Notes

- Supports single-digit integer operands (`0`-`9`), binary operators (`+`, `-`, `*`, `/`), and parentheses `(` `)`.
- Uses `cin >> infixExpression`, so input expressions should not contain spaces.
- Performs integer division (fractional parts are truncated).
- Note: `Expression_Evaluation_Infix_to_Postfix_Project_Report.docx` additionally documents an extended specification (including a `quit` loop, 90-character limit, syntax checks, and division-by-zero handling), whereas the C++ source file in this repository implements the core single-pass conversion and evaluation flow.
