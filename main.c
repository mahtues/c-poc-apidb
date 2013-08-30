#include <stdio.h>
#include "apidb.h"

int main(int argc, char **argv)
{
	accounts_row_t account_row;

	//account_row.account_id = 5;
	accounts_set_account_id(&account_row, 5);
	printf("id = %d.\n", account_row.account_id);
}
