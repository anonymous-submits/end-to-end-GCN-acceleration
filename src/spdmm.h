#include <stdio.h>
#include <ap_int.h>
#include <ostream>
/*
#define VDATA_SIZE 16
#define DENSE_BUFFER_LENGTH 4096
#define INDEX_BUFFER_LENGTH 16
#define OUTPUTBUFFER_LENGTH 32

#define datawidth 512

typedef float data_type;
typedef int index_type;
typedef ap_int<512> wid_data_type;
typedef union{unsigned int intdata; float floatdata;} convertion;

const int indexbufferlength = INDEX_BUFFER_LENGTH * VDATA_SIZE;

struct v_datatype {
    data_type data[VDATA_SIZE];
};

struct v_indextype {
	index_type data[VDATA_SIZE];
};

*/
void resetoutputBuffer(data_type outputBuffer[][VDATA_SIZE], int featurePn);


void loadinptr(index_type CSRindptrBuffer[][VDATA_SIZE],const v_indextype * CSRindptr, int k);

void spdmm(
    const wid_data_type * dense,  // dense matrix
    const v_indextype * CSRindptr,   // sparse martix is stored in CSR format, column value
    const index_type * CSRindex,      // row value
    const data_type * CSRvalue,    // data value
	wid_data_type * output,
    int k,   // partition size k
    int pn,  // number of partitions
    int pindex,  // current partition index
    int featurePn // size of the sparse matrix
);
