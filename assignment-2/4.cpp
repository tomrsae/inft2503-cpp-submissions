
int main() {
    // PROBLEM
    // int a = 5;
    // int &b; This line is missing an initializer
    // int *c;
    // c = &b;
    // *a = *b + *c; A is a regular integer, not a pointer. Thus the dereferencing operator "*" will not work.
    // &b = 2; It is not possible to set the address of a reference to a literal.

    // SOLUTION
    int a = 5;
    int &b = a;
    int *c;
    c = &b;
    a = b + *c;
    b = 2;

    // The assignment contains a lot of ambiguity as to what is required/desired.
    // It is only stated that we are to make the code compile.
    // Therefore, I had to make my own assumptions as to what was actually desired.

    return 0;
}