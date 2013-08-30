#include <stdio.h>
#include "apidb.h"

int main(int argc, char **argv)
{
	accounts_row_t account_row;

	account_row.account_id = 5;
	printf("id = %d.\n", account_row.account_id);

	APIDB_TYPE_INT(num);
	num = 5;
	printf("num = %d\n", num);
}
