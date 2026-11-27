#include "World/WorldInput.h"

#include "Config.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdint.h>
#include <vector>

uint8_t openWorld(int32_t *ponteiro)
{
	const char *fileLoc { RESOURCES_PATH "Maps/MapTest01.txt" };
	int8_t PONTARIA{ 0 };
	int32_t TestMaps[100];
	uint8_t index{ 0 };

	FILE *mapTest {fopen(fileLoc, "r")};
	if (mapTest == NULL)
	{
		std::cout << "\nERRO AO ABRIR ARQUIVO" << std::endl;
		return(-1);	// FAILURE
	}

	while(PONTARIA = fscanf(mapTest, "%d", &(ponteiro[index])) != EOF)
	{
		// DEBUG
		//printf("%d", TestMaps[index]);
		//printf("%d", PONTARIA);
		++index;
	}

	fclose(mapTest);

	return(0);	// SUCCESS
}

uint8_t closeWorld(void)
{
	return(0);	// SUCCESS
}