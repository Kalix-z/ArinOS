extern "C" void _start()
{
    char* video_memory = (char*)0xb8000;
    *video_memory = 'X';

    while(1){}
    return;
}
/**
 * 
 * 
 *     
 * char* ptr = (char*)0xB8000000;
    *ptr = 0x4F;
    ptr++;
    *ptr = 0x20;
 **/

