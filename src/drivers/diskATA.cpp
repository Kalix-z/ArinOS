// lowest level disk driver, do not use directly unless for a filesystem driver
#include "diskATA.h"

#define StatusRegister 0x1F7
#define CommandRegister 0x1F7
#define CylinderHighRegister 0x1F5

#define CylinderLowRegister 0x1F4
#define SectorCountRegister 0x1F2
#define FeaturesRegister 0x1F1
#define DataRegister 0x1F1
#define DeviceControlRegisters 0x3F6
#define DriveRegister 0x1F6

#define LBALo 0x1F3
#define LBAMid 0x1F4
#define LBAHigh 0x1F5


#define ERR 0
#define IDX 1
#define CORR 2
#define DRQ 3
#define SRV 4
#define DF 5
#define RDY 6
#define BSY 7

#define STATUS_BSY 0x80
#define STATUS_RDY 0x40
#define STATUS_DRQ 0x08
#define STATUS_DF 0x20
#define STATUS_ERR 0x01


static void ATA_wait_BSY();
static void ATA_wait_DRQ();

void read_sectors_ATA_PIO(size_t target_address, size_t LBA, uint8_t sector_count)
	{

		ATA_wait_BSY();
		outb(0x1F6,0xE0 | ((LBA >>24) & 0xF));
		outb(0x1F2,sector_count);
		outb(0x1F3, (uint8_t) LBA);
		outb(0x1F4, (uint8_t)(LBA >> 8));
		outb(0x1F5, (uint8_t)(LBA >> 16)); 
		outb(0x1F7,0x20); //Send the read command

		uint16_t *target = (uint16_t*) target_address;

		for (int j =0;j<sector_count;j++)
		{
			ATA_wait_BSY();
			ATA_wait_DRQ();
			for(int i=0;i<256;i++)
				target[i] = inw(0x1F0);
			target+=256;
		}
	}

void write_sectors_ATA_PIO(size_t LBA, uint8_t sector_count, size_t* bytes)
{
    ATA_wait_BSY();
    outb(0x1F6,0xE0 | ((LBA >>24) & 0xF));
    outb(0x1F2,sector_count);
    outb(0x1F3, (uint8_t) LBA);
    outb(0x1F4, (uint8_t)(LBA >> 8));
    outb(0x1F5, (uint8_t)(LBA >> 16)); 
    outb(0x1F7,0x30); //Send the write command

    for (int j =0;j<sector_count;j++)
    {
        ATA_wait_BSY();
        ATA_wait_DRQ();
        for(int i=0;i<256;i++)
        {
            outl(0x1F0, bytes[i]);
        }
    }
}

static void ATA_wait_BSY()   //Wait for bsy to be 0
{
    while(inb(0x1F7)&STATUS_BSY);
}
static void ATA_wait_DRQ()  //Wait fot drq to be 1
{
    while(!(inb(0x1F7)&STATUS_RDY));
}