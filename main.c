#include <stdio.h>
#include <string.h>

/*external variables specific to the RPN*/
int first_value = 0;
int second_value = 0;
int total = 0;
bool valid = true;

//This is the code for a stack
#define STACK_SIZE 100

/*external variables*/
int contents[STACK_SIZE];
int top = 0;

void make_empty(void) {
    top = 0;
}
bool is_empty(void) {
    return top == 0;
}
bool is_full(void) {
    return top == STACK_SIZE;
}
void push(int i) {
    if (is_full()) {
        printf("Stack is full\n");
    }
    else {
        contents[top++] = i;
    }
}
int pop(void) {
    if (is_empty()) {
        printf("popped element is empty\n");
    }
    else {
        return contents[--top];
    }
}
//Stack example end

int Reverse_Polish_Notation() {
    char input[201] = "";
    printf("Please enter an expression: ");
    fgets(input, sizeof(input), stdin);
    for (int x = 0; x < strlen(input); x++) {
        switch (input[x]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                push(input[x] - '0');
                break;
            case '+':
                first_value = pop();
                second_value = pop();
                total = first_value + second_value;
                push(total);
                break;
            case '-':
                first_value = pop();
                second_value = pop();
                total = second_value - first_value;
                push(total);
                break;
            case '*':
                first_value = pop();
                second_value = pop();
                total = first_value * second_value;
                push(total);
                break;
            case '/':
                first_value = pop();
                second_value = pop();
                total = second_value / first_value;
                push(total);
                break;
            case '=':
                total = pop();
                printf("Answer: %d\n",total);
                first_value = 0;
                second_value = 0;
                total = 0;
                for (int y = 0; y < STACK_SIZE; y++) {
                    make_empty();
                }
                for (int z = 0; z < sizeof(input); z++) {
                    input[z] = 0;
                }
                break;
            //Note to self: Interestingly enough, after entering a new expression, we add a new line
            //This works against us as the program will read the empty value and give us 10, which
            //is the value for a new line and that counts as a non-integer and/or non-operation value.
            //Thus it just... BREAKS???? So these 3 lines of code guard against that.
            case ' ':
            case '\n':
                break;
            default: {
                    printf("Invalid input: %d\n", input[x]);
                    valid = false;
                    break;
                }
        }
    }
}

int main(void) {
    while (valid == true) {
        Reverse_Polish_Notation();
    }
    return 0;
}
