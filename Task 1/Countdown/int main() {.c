int main() {
    char input[100];  // Define a character array to store the input
    printf("Enter a string with spaces: ");
    fgets(input, sizeof(input), stdin);  // Read input from the user

    printf("You entered: %s", input);  // Print the input

    return 0;
    