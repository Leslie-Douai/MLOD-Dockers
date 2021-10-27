#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "linkedList.h"

typedef struct {
	char* name;
	char* artist;
	char* album;
	char* genre;
	char* DiscNumber;
	char* trackNumber;
	char* year;
} Music;



typedef Liste MusicList;
