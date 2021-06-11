#include "Types.h"
#include "IO.h"

//Reads Disk
void ReadSector(uint_32 sector_number, uint_32 byteCount) {
    outb(0x1f2, byteCount / 512);
    outb(0x1F3, sector_number);
    outb(0x1F4, 0);
    outb(0x1F5, 0);
    outb(0x1F7, 0x20);
}
