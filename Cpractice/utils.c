#include"utils.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

bool hasMember(
    const void* structPtr, 
    size_t structSize, 
    const char* memberName
) {
    const char* memberPtr = (const char*)structPtr;

    for (size_t offset = 0; offset < structSize; ++offset) {
        if (strcmp(memberPtr + offset, memberName) == 0) {
            return true;
        }
    }

    return false;
}
