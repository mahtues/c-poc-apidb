#include <stdio.h>
#include "apidb.h"

int main(int argc, char **argv)
{
	accounts_row_t account_row;

	//account_row.account_id = 5;
	accounts_row_set_account_id(&account_row, 5);
	printf("id = %d\n", account_row.account_id);

	accounts_row_set_name(&account_row, "123456789012345678901234567890");
	printf("name = '%s'\n", account_row.name);
	printf("strlen = %d\n", strlen(account_row.name));
}
