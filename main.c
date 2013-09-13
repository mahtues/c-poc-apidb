#include <stdio.h>
#include "apidb.h"

int main(int argc, char **argv)
{
	accounts_entry_t account_entry;

	accounts_entry_set_account_id(&account_entry, 5);
	printf("id = %d\n", account_entry.account_id);

	accounts_entry_set_name(&account_entry, "123456789012345678901234567890");
	printf("name = '%s'\n", account_entry.name);
	printf("strlen = %d\n", strlen(account_entry.name));
}
