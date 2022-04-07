#include <iostream>

using namespace std;

int main()
{
    
    char in_format[] = "%d";

   
    const int M = 3;
    const int N = 4;
    int matrix[M][N];

    int* arr = &matrix[0][0];
    char* in_form = &in_format[0];


    cout << "Enter " << M * N << " numbers:" << endl;
    asm (
            "movl %[M], %%eax;"     
            "movl %[N], %%ebx;"
            "mov %[arr], %%rsi;"
            "mov %[in_form], %%rdi;"

            
            "mull %%ebx;"
            "movl %%eax, %%r12d;"

            
        "input: "
            
            "push %%rsi;"
            "push %%rdi;"
           
            "call scanf;"
            
            "pop %%rdi;"
            "pop %%rsi;"

            "addq $4, %%rsi;"
            "dec %%r12d;"
           
            "cmpl $0, %%r12d;"
           
            "jne input"
            :
            :[arr]"m"(arr), [M]"m"(M), [N]"m"(N), [in_form]"m"(in_form)
            :
        );

   
    cout << "\nMatrix [" << M << "][" << N << "]" << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << matrix[i][j] << "  ";
        cout << endl;
    }

    return 0;
}
