#include <stdio.h>
#include <stdlib.h>

#define int16_t short
#define uint32_t unsigned int
#define INVALID_VALUE32 -1
#define RETURN_OK 0
#define RETURN_ERROR -1
#define RETURN_END_OF_TABLE -2
#define MAX_INDEX 3

uint32_t get_local_key_id(uint32_t curKey, uint32_t *nextKey);

int16_t g_localNodeId = 1;

int16_t getLocalKeyId(void)
{
	return g_localNodeId;
}

int main()
{
	uint32_t cur_key = INVALID_VALUE32;
	uint32_t next_key = 0;
	while (INVALID_VALUE32 != next_key)
	{
		get_local_key_id(cur_key, &next_key);
		cur_key = next_key;
		printf("Now current key is: %u\n", cur_key);
	}

	system("pause");
	return 0;
}

uint32_t get_local_key_id(uint32_t curKey,
							uint32_t *nextKey)
{
	int16_t local_node_id = getLocalKeyId();
	uint32_t cur_index = 0;
	uint32_t node_id = (uint32_t)local_node_id << 16;

	if (NULL == nextKey)
	{
		printf("Param input nextKey is NULL.");
		return RETURN_ERROR;
	}

	if (INVALID_VALUE32 == curKey)
	{
		*nextKey = (uint32_t)node_id;
		return RETURN_OK;
	}

	cur_index = curKey & 0x0000ffff;


	if (cur_index == MAX_INDEX)
	{
		*nextKey = INVALID_VALUE32;
		return RETURN_END_OF_TABLE;
	}
	else
	{
		*nextKey = node_id + cur_index + 1;
		return RETURN_OK;
	}
}

