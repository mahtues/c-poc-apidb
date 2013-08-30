#include "apidb_types.h"
#include <string.h>

#define COLUMN_DESC(_type, _length, _name)

/* table definition start [ */
#define TABLE_NAME accounts

#define TABLE_COLUMNS \
	COLUMN_DESC(int, 1, account_id) \
	COLUMN_DESC(char, 20+1, name)

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
#define COLUMN_DESC(_type, _length, _name) \
	_type _name[_length];
typedef struct {
	TABLE_COLUMNS
} TABLE_ROW_STRUCT_NAME;
#undef COLUMN_DESC

/*****************************************************************************
 * set column
 *****************************************************************************/
#define COLUMN_DESC(_type, _length, _name) \
	int CONCAT(CONCAT(TABLE_NAME, _set_), _name)(TABLE_ROW_STRUCT_NAME *row, _type *_value) {\
		memcpy(row->_name, _value, sizeof(_type) * _length); \
		return 0; \
	}
TABLE_COLUMNS
#undef COLUMN_DESC
