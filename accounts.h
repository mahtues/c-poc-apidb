#include "apidb_types.h"

#define COLUMN_DESC(column)

/* table definition start [ */
#define TABLE_NAME accounts

#define TABLE_COLUMNS \
	COLUMN_DESC(APIDB_TYPE_INT(account_id)) \
	COLUMN_DESC(APIDB_TYPE_STRING(name, 20))

/* table definition end ]*/

#undef COLUMN_DESC

/* crazy macros for crazy macro manipulations */
#define QUOTE(str) #str
#define EXPAND(str) str
#define EXPAND_AND_QUOTE(str) QUOTE(str)

#define _CONCAT(str1, str2) str1 ## str2
#define CONCAT(str1, str2) _CONCAT(str1, str2)

//#define TABLE_HEADER_DESC_FILE EXPAND_AND_QUOTE(CONCAT(TABLE_NAME, _desc.h))

#define TABLE_ROW_STRUCT_NAME EXPAND(CONCAT(TABLE_NAME, _row_t))

/*****************************************************************************
 * row definition
 *****************************************************************************/
#define COLUMN_DESC(column) \
	column;
typedef struct {
	TABLE_COLUMNS
} TABLE_ROW_STRUCT_NAME;
#undef COLUMN_DESC

