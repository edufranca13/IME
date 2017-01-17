EXTERN main
hello STR "Hello␣World!\n"
main GETA $0, hello 
PUSH $0
CALL puts
INT 0
