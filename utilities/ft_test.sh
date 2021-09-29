norminette -R CheckForbiddenSourceHeader */*.c 
gcc -c -Wall -Wextra -Werror */*.c
rm *.o
echo "-------------------------------------------------------"
ls */*
