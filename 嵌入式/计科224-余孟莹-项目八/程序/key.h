void key(void)
{
	P2 = 0xef;
	if(P2 == 0xee)
	{
		cp3++;
		if(cp3 >= 7)cp3 = 2;
	}
	while(P2 == 0xee);
	if(P2 == 0xed)
	{
		if(cp3 == 2){hour++;if(hour >= 24)hour = 0;}
		if(cp3 == 3){min++;if(min >= 60)min = 0;}
		if(cp3 == 4){sec++;if(sec >= 60)sec = 0;}
		if(cp3 == 5){hour_n++;if(hour_n >= 24)hour_n = 0;}
		if(cp3 == 6){min_n++;if(min_n >= 60)min_n = 0;}
	}
	while(P2 == 0xed);
	if(P2 == 0xed)
	{
		if(cp3 == 2){hour++;if(hour >= 24)hour = 23;}
		if(cp3 == 3){min++;if(min >= 60)min = 59;}
		if(cp3 == 4){sec++;if(sec >= 60)sec = 59;}
		if(cp3 == 5){hour_n++;if(hour_n >= 24)hour_n = 23;}
		if(cp3 == 6){min_n++;if(min_n >= 60)min_n = 23;}
	}
	while(P2 == 0xed);
	if(P2 == 0xeb)
	{
		if(cp3 == 2){hour--;if(hour <= 0)hour = 0;}
		if(cp3 == 3){min--;if(min <= 0)min = 0;}
		if(cp3 == 4){sec--;if(sec <= 0)sec = 0;}
		if(cp3 == 5){hour_n--;if(hour_n <= 0)hour_n = 0;}
		if(cp3 == 6){min_n--;if(min_n <= 0)min_n = 0;}
	}
	while(P2 == 0xeb);
	if(P2 == 0xe7)
	{
		cp3 = 1;
	}
	while(P2 == 0xe7);
}