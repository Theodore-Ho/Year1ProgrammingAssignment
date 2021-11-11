# Overall
You are required to develop a program that will perform security authorisation based on numeric codes. The codes are four (4) single-digit integer numbers between 0-9. The program should allow a user to enter any four-digit code or generate a random code, encrypt the code and compare it to a fixed, authorised access code. The program should also allow the user to decrypt an already encrypted code.

You are required to develop a program that will perform security authorisation based on numeric codes. The codes are four (4) single-digit integer numbers between 0-9. The program should allow a user to enter any four-digit code or generate a random code, encrypt the code and compare it to a fixed, authorised access code. The program should also allow the user to decrypt an already encrypted code.

Your program must be menu-driven and must display a simple menu when executed. The menu must include the following options:

1. Enter a code or generate a random code
2. Encrypt code
3. Check if the encrypted code matches the default authorised access code, i.e., 4523
4. Decrypt code
5. Display the number of times the encrypted code is: Correct, Wrong.
6. Exit Program

Note:
- Each menu option must be implemented in a separate function
- All functions must pass parameters using Pass by Reference. Do not pass parameters using pass by value.
- All reading and writing to/from arrays must use pointer notation only – do not use subscript notation (i.e. using square braces) to access your array(s).

# Requirements
- The user must choose whether to enter any four (4) single-digit integers or generate a random code (0000 – 9999 inclusive). Perform any necessary validation (error-checking).
- Encrypt the code entered. You should use the following algorithm to encrypt the 4 single-digit integer code:
  - Swap the 1st number with the 3rd number.
  - Swap the 2nd number with the 4th number.
  - Add 1 to each number.
  - If any number has a value equal to 10, change this value to 0. 
- Compare the encrypted code with the access code (4523) stored in the 1-Dimensional array called access_code. If the two codes match, display a message saying “Correct Code entered”. If the two codes do not match, display a message saying “Wrong Code entered” .
- Decrypt an encrypted code. You should use the following algorithm to decrypt an encrypted code only:
  - Subtract 1 from each number.
  - If any number has a value equal to -1, change this value to 9.
  - Swap the 1st number with the 3rd number.
  - Swap the 2nd number with the 4th number.
- Using the following Structure template, count and display the number of times the encrypted code is correct and/or wrong in each run of the program:
```c
struct code_counter {
  int correct_code;
  int wrong_code;
};
```
- The program should terminate gracefully.
