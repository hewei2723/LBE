#include <stdio.h>
 #include <stdlib.h>
 #include <malloc.h>
 struct node
 {
  int    vertex;
  struct  node   *next;
  };
 struct   headnode
 {
   int     vert;
   struct  node   *link;
  };
main()
   {
	 int t,n,i,visit[100];
	 int d[100];
	 struct headnode  *adjlist( );
	 void dfs( );
	 void wfs( );
	 struct headnode  *head ;
	 printf("input the sum of nodes:\n");
	 scanf("%d",&n);
	 for(i=0;i<n;i++)
	 scanf("%d",&d[i]);
	 head=adjlist(d,n);
	 printf("1 depth  travel\n");
	 printf("2 width  travel\n");
	 printf("please input the way of travelling\n");
	 scanf("%d",&t);
	 switch  (t)
	  {
		case 1:
			  for(i=0;i<n;i++)
				 visit[i]=0;
			  dfs(head,1,visit);
			  break;
		case 2:
			wfs(head,n);
			break;
		default:
			printf("The  error!");
	   }
  }
struct headnode  *adjlist(d,n)
	  int    n;
	  int	 d[ ];
	  {
		struct  headnode  head[100] ;
		struct   node     *q,*p ;
		int     i,v1;
	 for(i=0; i<n;i++)
	  {
		head[i].vert=d[i];
		head[i].link=NULL;
		printf("input linked  list  of\n");
		scanf("%d ",&v1);
		while(v1>=0)
		 {
			p=(struct node *) malloc(sizeof(struct  node));
			p->vertex=v1;
			p->next=head[i].link ;
			head[i].link=p;
			scanf("%d", &v1);
		   }

		}
 return(head);
 }
 void  dfs(head,k,visit)
	   struct  headnode  head[1000];
	   int  k,visit [ ];
	   {
		int  i;
		struct  node  *p;
		printf(" v%d",k);
		visit[k]=1;
		p=head[k-1].link;
		while ( p!=NULL)
		 {
		  if (visit[p->vertex]==0)
		  dfs(head,p->vertex,visit);
		  p=p->next;
		 };
 return;
 }
void wfs(head,n)
struct headnode  *head;
int n;
{
 int visit[1000],q[1000],f,r,k,u,m;
 struct node *p;
 for(k=0;k<n;k++)
   visit[k]=0;
  f=0;
  r=0;
  m=0;
  if (visit[m]==0)
	q[r]=(head+m)->vert;
	r=r+1;
	visit[m]=1;
  while (f!=r)
   {
	 u=q[f];
	 f=f+1;
	 printf(" v%d",u);
	 p=(head+u-1)->link;
	 while (p!=NULL)
	  {
		if (visit[p->vertex-1]==0)
		 {
		   q[r]=p->vertex;
		   r=r+1;
		   visit[p->vertex-1]=1;
		  }
		p=p->next;
	   }
	 }
 }