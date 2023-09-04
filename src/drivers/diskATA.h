#ifndef DISKATA_H
#define DISKATA_H

#include <stdint.h>
#include <io.h>
#include <screen.h>

void write_sectors_ATA_PIO(size_t LBA, uint8_t sector_count, size_t* bytes);

void read_sectors_ATA_PIO(size_t target_address, size_t LBA, uint8_t sector_count);

#endif