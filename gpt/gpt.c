#include <stdio.h>
#include <string.h>
#include <stdint.h>


struct mbr_entry
{
	uint8_t boot_indicator;
	uint8_t starting_chs[3];
	uint8_t type;
	uint8_t ending_chs[3];
	uint8_t x[4];
	uint8_t y[4];
	//uint32_t starting_sector;
	//uint32_t partition_size;
};


struct table
{
	//uint8_t blank[2];
	uint8_t arr[0x1be];
	struct mbr_entry p1;
	struct mbr_entry p2;
	struct mbr_entry p3;
	struct mbr_entry p4;
	uint8_t signature[2];
};


int main()
{
	struct table t;
	
	
	FILE * img = fopen("lba03", "r");
	if(NULL == img)
	{
		printf("cannot open img.\n");
		return -1;
	}
	
	int ret = fread(&(t.arr), 1, sizeof(t), img);
	printf("ret = %d\n", ret);
	
	
	printf("type = 0x%x\n", t.p1.type);
	uint32_t Y = *((uint32_t *)(t.p1.y));
	printf("Y = 0x%x\n", Y);
	
	return 0;
}
