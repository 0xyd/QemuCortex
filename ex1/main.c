void PUT32 ( unsigned int, unsigned int );
#define UART0BASE 0x40005000
int main(int argc, char const *argv[])
{
	unsigned int rx;
    for(rx=0;rx<8;rx++)
    {
        PUT32(UART0BASE+0x00,0x30+(rx&7));
    }
	return 0;
}