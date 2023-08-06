#include "ft_printf.h"
// #include <stdio.h>

// int main()
// {
// 	int num1 = printf("NULL (null) NULL", NULL);
// 	printf("\n");
// 	int num2 = ft_printf("NULL (null) NULL", NULL);
// 	printf("\n");
// 	printf("original : %d\nft : %d", num1, num2);

// }
#include <stdio.h>

int main()
{
	int num1 = printf("%d %d", -10);
	printf("\n");
	int num2 = ft_printf("%d %d", -10);
	printf("\n");
	printf("original : %d\nft : %d", num1, num2);

}