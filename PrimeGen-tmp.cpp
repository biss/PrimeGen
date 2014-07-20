#include<stdio.h>
#include<math.h>

int a[39] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,
           107,109,113,127,137,139,149,151,157,163,167,173};
int b[31623] = {0}, n, m, i;
int p_count = 0;
int p[31622] = {0};

int main() {
    double div;
    int diff, k, f=0, upper, lower;
    int r[100000] = {0}, j=0;
    b[0] = 1;
    b[1] = 1;
    
    for(i=0; i<39; i++)  {
           m = 2*a[i];
           while(m<31623)  {
                           b[m]=1;
                           m=m+a[i];
                           }
           }
    for(i=0; i<31623; i++)        {
            if(b[i]==0)
               p[p_count++]=i;
            }
    printf("Number of test cases?");
    scanf("%d", &n);
    
    while(n--)  {
                scanf("%d %d", &lower, &upper);
                diff = upper-lower+1;                     
                if(upper>31623)    {
                                   int c=diff;
                                   while(diff>0)      {
                                      r[diff] = 0;
                                      diff--;
                                      }
                                   
                                   if(lower==1)
                                   r[0]=1;
                                   
                                   for(i=0; i<p_count; i++)   {
                                            if(upper>p[i])    {
                                                    div = (double)lower/p[i];
                                                    k = (int)ceil(div);
                                                    if(k==1)
                                                       m = 2*p[i] - lower;
                                                    else
                                                       m = k*p[i] - lower;
                                                    
                                                    while(m<c) {
                                                                  r[m] = 1;
                                                                  m = m+p[i];
                                                                  }
                                                    }
                                                    }
                                   while((lower + f)<=upper) {
                                                     if(r[f]==0)
                                                     {printf("%d", lower+ f);
                                                     printf("\n");}
                                                     f++;
                                                     }
                                   }
                else
                    while((diff--)>0)                {
                                                     if(b[lower]==0)
                                                     {printf("%d", lower);
                                                     printf("\n");}
                                                     lower++;
                                                     }
    }
    return 0;
}

