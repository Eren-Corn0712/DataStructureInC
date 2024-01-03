#pragma once
#ifndef UTILS_H
#define UTILS_H
#include<stdbool.h>

bool hasMember(
	const void* structPtr,
	size_t structSize,
	const char* memberName
);

#endif // !UTILS_H
