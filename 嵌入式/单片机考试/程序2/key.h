void key(void)
{
	P2 = 0xef;
	if(P2 == 0xee)
	{
		cp3++;
		if(cp3 >= 4)cp3 = 1;	
	}
	while(P2 == 0xee);
	if(P2 == 0xed)
	{
		if(cp3 == 1){hour++;if(sec >= 60)hour = 0;}
		if(cp3 == 2){min++;if(min >= 60)min = 0;}		
		if(cp3 == 3){sec++;if(sec >= 60)sec = 0;}	
		if(cp3 == 4){hour_n++;if(hour_n >= 24)hour_n = 0;}
		if(cp3 == 5){min_n++;if(min_n >= 60)min_n = 0;}	
		time_adj();					
	}
	while(P2 == 0xed);
	if(P2 == 0xeb)
	{
		if(cp3 == 1){hour--;if(sec <= 0)hour = 0;}
		if(cp3 == 2){min--;if(min <= 0)min = 0;}		
		if(cp3 == 3){sec--;if(sec <= 0)sec = 0;}	
		if(cp3 == 4){hour_n--;if(hour_n <= 0)hour_n = 0;}
		if(cp3 == 5){min_n--;if(min_n <= 0)min_n = 0;}			
		time_adj();					
	}
	while(P2 == 0xeb);

	if(P2 == 0xe7)
	{
		cp3 = 0;				
	}
	while(P2 == 0xe7);
}