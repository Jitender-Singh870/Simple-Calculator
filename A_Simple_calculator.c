#include <stdio.h>

int check(char s) {
    switch (s) {
        case '-':
            return 1;

        case '+':
            return 1;

        case '/':
            return 1;

        case '*':
            return 1;
    
        default:
            return 0;
    }
}


int main() {

    int n = 0;
    while (n == 0){   
        char sign = 'o';
        double first, second;

        while (check(sign) == 0) {
            printf("Enter an operator (+, -, *, /, e for exit): ");
            scanf(" %c", &sign);
            if (sign == 'e') {
                goto exit;
            } else if (check(sign) == 0) {
                printf("invalid input please try again:\n");
                while((sign = getchar()) != EOF && sign != '\n');
            } 
        }
        printf("Enter First Number: ");
        scanf(" %lf", &first);
        
        printf("%.1lf %c ", first, sign);
        scanf(" %lf", &second);
        if (sign == '/' && second == 0){
            printf("Division with 0 is not possible.\n");
            continue;
        }
        switch (sign) {
            case '+':
                printf("%.1lf + %.1lf = %.1lf\n", first, second, first + second);
                break;
            case '-':
                printf("%.1lf - %.1lf = %.1lf\n", first, second, first - second);
                break;
            case '*':
                printf("%.1lf * %.1lf = %.1lf\n", first, second, first * second);
                break;
            case '/':
                printf("%.1lf / %.1lf = %.1lf\n", first, second, first / second);
                break;

            default:
                printf("Error! operator is not correct\n");
        }
        continue;
        exit:
            printf("Now exiting the calculator.\n");
            n = 1;
    }
    return 0;
}
