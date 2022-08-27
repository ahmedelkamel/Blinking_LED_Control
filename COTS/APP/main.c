#include "Blink.h"

int main(void)
{
	Blink_Init();	
	while(1)
	{
		Blink_Running();
	}
	return 0;
}
