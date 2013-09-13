#include "apidb_types.h"
#include <string.h>

#define COLUMN_DESC(_name, _type, _length)

/* table definition start [ */
#define TABLE_NAME accounts

#define TABLE_COLUMNS \
	COLUMN_DESC(account_id, INT, 0) \
	COLUMN_DESC(name, STR, 20)

/* table definition end ]*/

#undef COLUMN_DESC

/* crazy macros for crazy macro manipulations */
#define QUOTE(str) #str
#define EXPAND(str) str
#define EXPAND_AND_QUOTE(str) QUOTE(str)

#define _CONCAT(str1, str2) str1 ## str2
#define CONCAT(str1, str2) _CONCAT(str1, str2)

#define _CONCAT3(str1, str2, str3) str1 ## str2 ## str3
#define CONCAT3(str1, str2, str3) _CONCAT3(str1, str2, str3)

//#define TABLE_HEADER_DESC_FILE EXPAND_AND_QUOTE(CONCAT(TABLE_NAME, _desc.h))
#define TABLE_ENTRY_STRUCT_NAME EXPAND(CONCAT(TABLE_NAME, _entry_t))

/*****************************************************************************
 * entry definition
 *****************************************************************************/
#define COLUMN_DESC(_name, _type, _length) \
	APIDB_TYPE_  ## _type ## _DEC(_name, _length);
typedef struct {
	TABLE_COLUMNS
} TABLE_ENTRY_STRUCT_NAME;
#undef COLUMN_DESC

/*****************************************************************************
 * set column
 *****************************************************************************/
#define COLUMN_DESC(_name, _type, _length) \
	int CONCAT3(TABLE_NAME, _entry_set_, _name)(TABLE_ENTRY_STRUCT_NAME *entry, APIDB_TYPE_ ## _type ## _PRM(value)) {\
		APIDB_TYPE_ ## _type ## _SET(entry->_name, value); \
		return 0; \
	}
TABLE_COLUMNS
#undef COLUMN_DESC

#undef TABLE_COLUMNS
#undef TABLE_NAME
#undef TABLE_ENTRY_STRUCT_NAME
