# define MAX 128
main()
{
    int i,k,m,n,result;
    int a[MAX];
    printf("How many nodes in the array \n");
    scanf("%d",&n);
    printf("Please input the value of array element\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("The key word?");
    scanf("%d",&k);
    printf("Please Input Your Choice(1-2):");
    scanf("%d",&m);
    switch(m)
    {
        case 1:
            printf("This is ShunXu Search!\n");
	    result=shx(a,n,k);
	    if(result>=0) 
	    	printf("Found No.%d  elements of the array\n",result+1);
	    else 
	    	printf("Not found\n");
	    break;
        case 2:
            printf("This is ErFen Search!\n");
	    result=erfen(a,n,k);
	    if(result>=0) 
	    	printf("In the No. %d of the array\n",result+1);
	    else 
	    	printf("Not found\n");
	    break;
        default:
            printf("1-------------------------ShunXu Search\n");
	    printf("2-------------------------ErFen Search\n");
	    return;
    }
}

int  shx (array, n, k)
	/*find the subscript of an element's which value is k in array[n]*/
int  array[], n, k;
{  
    int  i;
    array[n]=k;/*watch*/
    i= 0;
    while (array[i]!=k) i++;
    if (i<n) return (i);
    else return (-1);
}

int erfen(int array[],int n ,int key)
 /*find key in array[] whose length is n,if it is found,then return its address,else return -1*/
{
    int l, r,mid;
    l=0; 
    r=n-1;
    while (l<=r)
    {
    	mid=(l+r)/2;
   	if(key==array[mid])  
   	    return mid;   /*it is found,return its address*/
        else if(key<array[mid])   
            r=mid-1;
        else l=mid+1;
    }
    return -1;
}
