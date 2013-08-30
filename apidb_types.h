#ifndef APIDB_TYPES
#define APIDB_TYPES

/* declarations */
#define APIDB_TYPE_INT_DEC(_name, _length) int _name
#define APIDB_TYPE_STR_DEC(_name, _length) char _name[_length+1]

#define APIDB_TYPE_INT_PRM(_name) int _name
#define APIDB_TYPE_STR_PRM(_name) char *_name

#define APIDB_TYPE_INT_SET(_dst, _src) (_dst) = (_src)
#define APIDB_TYPE_STR_SET(_dst, _src) { memset(_dst, 0, sizeof(_dst)); memcpy((_dst), (_src), strlen((_src)) < sizeof((_dst)) ? strlen((_src)) : sizeof(_dst) - 1 ); }

#define APIDB_TYPE_INT_GET(_src) (_src)
#define APIDB_TYPE_STR_GET(_src) (_src)

#endif
