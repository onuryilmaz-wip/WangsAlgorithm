/* Onur YILMAZ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function for copying string from 'from' to 'to' */
void my_strcopy(char *to, char* from)
{
while((*to++=*from++));
}

/* Function for locating the first occurence of pattern in str */
char* strloc(char* str, char* pattern)
{
char *cp;

for(cp=str; (cp=strchr(cp, *pattern)); (cp++))
	if(!strncmp(cp, pattern, strlen(pattern) )) 
		return cp;
		return NULL;
}

/* Main function */
int main()
{

int my_func(char*, char*);
char *girdi1, *girdi2;
char *p_girdi1;
char *p_girdi2;
int donen1;

/* Allocating memory for input entries */
girdi1=malloc(sizeof(char)*200);
p_girdi1=girdi1;
girdi2=malloc(sizeof(char)*200);
p_girdi2=girdi2;

/* Reading the input */
scanf("%s", girdi1);

/* Dividing the input string into two */
while(*p_girdi1)
{
if(*p_girdi1=='#')
{ 
	p_girdi1++;
	my_strcopy(p_girdi2, p_girdi1);
	p_girdi1--;
	*p_girdi1='\0';
}
p_girdi1++;
}

/* Pointers for two strings */
p_girdi1=girdi1;
p_girdi2=girdi2;

/*Return value of algorithm */
donen1=my_func(p_girdi1,p_girdi2);

/*Printing the result */
if(donen1==2 || donen1==1) printf("T\n"); else if(donen1==3 || donen1==0) printf("F\n"); else;

/*
printf("%s\n", p_girdi1);
printf("%s\n", p_girdi2);
*/

return 0;
}

/* Function for R5 */
void transformation5(char* trp_girdi1)
{
char *bir_bas;
char *p_bir;
char *ilk_virgul;
char *ikinci_virgul;
char *kontrol;
char *virgul;
char *eksi;
char *veya;
char *parantezac;

parantezac="(";
veya="|";
eksi="-";
virgul=",";
bir_bas=trp_girdi1;
p_bir=bir_bas;

while(*p_bir)
{

if(*p_bir=='>')
{
	/* Locate the previous comma */
	for(kontrol=p_bir;kontrol>=bir_bas;kontrol--)
	if(*kontrol==',' || kontrol==bir_bas ) 
	{ 
	ilk_virgul=kontrol; break;
	}


	/*Locate the next comma */
	for(kontrol=p_bir;;kontrol++)
	if(*kontrol==',' || *kontrol=='\0' ) 
	{ 
	ikinci_virgul=kontrol; break;
	}

	/*Add the part from first comma to '>' by adding minus sign */

	if(*(ilk_virgul+1)=='-') 
	{
	strncat(bir_bas,(ilk_virgul),3); 
	strcat(bir_bas,eksi); 
	strncat(bir_bas,(ilk_virgul+3),(p_bir-ilk_virgul-3)); 
	strcat(bir_bas,veya); 
	strncat(bir_bas,(p_bir+1),(ikinci_virgul-p_bir-1));
	}

	else {
	strncat(bir_bas,(ilk_virgul),2); 
	strcat(bir_bas,eksi); 
	strncat(bir_bas,(ilk_virgul+2),(p_bir-ilk_virgul-2)); 
	strcat(bir_bas,veya); 
	strncat(bir_bas,(p_bir+1),(ikinci_virgul-p_bir-1));
	}

	/* Remove the parts between commas */

	for(;*ikinci_virgul;ikinci_virgul++,ilk_virgul++)
	{ 
	*ilk_virgul=*ikinci_virgul; 
	*ikinci_virgul='\0';
	}
}
p_bir++;
}
}


/* Function for R2 */
void transformation2(char* trp_girdi1, char* trp_girdi2)
{
while(*trp_girdi1)
{
	if(*trp_girdi1=='&') 
		*trp_girdi1=',';
	trp_girdi1++;
}

while(*trp_girdi2)
{ 
	if(*trp_girdi2=='|') 
		*trp_girdi2=',';
	trp_girdi2++; 
}

}

/* Function for correcting double comma, double minus, etc. */
void duzeltme1(char* trp_girdi1, char* trp_girdi2)
{

char* birinci;
char* birincip;
char* ikincip;
char *tasimali; 

tasimali=malloc(200*sizeof(char));

/* Adding comma to the beginning */
birinci=trp_girdi1;
if(*birinci!=',' )
{
my_strcopy(tasimali,trp_girdi1);
trp_girdi1[0]=',';
my_strcopy(trp_girdi1+1, tasimali);
}

/* Adding comma to the end */
birinci=trp_girdi1;
for(;*birinci;birinci++)
	if(*birinci!=',' && *(birinci+1)=='\0') 
	{ 
	*(birinci+1)= ','; 
	*(birinci+2)= '\0'; break;
	} 
	else;

/* Removing double commas */
birinci=trp_girdi1;
for(;*birinci;birinci++) 
{
if(*birinci==',' && *(birinci+1)==',')
	for(birincip=birinci,ikincip=birinci+1; *ikincip ; ikincip++,birincip++)
	{ 
	*birincip=*ikincip; *ikincip='\0';
	}
}

/* Removing double minus signs */
birinci=trp_girdi1;
for(;*birinci;birinci++) 
{
if(*birinci=='-' && *(birinci+1)=='-')
	for(birincip=birinci,ikincip=birinci+2; *ikincip ; ikincip++,birincip++)
	{ 
	*birincip=*ikincip; *ikincip='\0';
	}
}

/* For string 2 */

/* Adding comma to the beginning */
birinci=trp_girdi2;
if(*birinci!=',' )
{
	my_strcopy(tasimali,trp_girdi1);
	trp_girdi1[0]=',';
	my_strcopy(trp_girdi1+1, tasimali);
}

/* Adding comma to the end */
birinci=trp_girdi2;
for(;*birinci;birinci++)
	if(*birinci!=',' && *(birinci+1)=='\0') 
	{ 
	*(birinci+1)= ','; 
	*(birinci+2)= '\0'; break;
	} 
	else;


/* Removing double comma  */
birinci=trp_girdi2;
for(;*birinci;birinci++) 
{
if(*birinci==',' && *(birinci+1)==',')
	for(birincip=birinci,ikincip=birinci+1; *ikincip ; ikincip++,birincip++)
	{ 
	*birincip=*ikincip;
	*ikincip='\0';
	}
}

/* Removing double minus signs */
birinci=trp_girdi2;
for(;*birinci;birinci++) 
{
	if(*birinci=='-' && *(birinci+1)=='-')
	for(birincip=birinci,ikincip=birinci+2; *ikincip ; ikincip++,birincip++)
	{ 
	*birincip=*ikincip; *ikincip='\0';
	}
}

}

/* Function for R6 */
/* Termination 1 */
int termination6(char* trp_girdi1, char* trp_girdi2)
{

char *kontrol;
char *p_bir;
char *ikinci_virgul;
char *kopyalancak;
p_bir=trp_girdi1;

while(*p_bir)
{

	if(*p_bir==',' && *(p_bir+1)!='\0')
	{
	kopyalancak=calloc(200,sizeof(char));
		/* Locate the next comma */
		for(kontrol=p_bir+1;;kontrol++)
		{
		if(*kontrol==',')
		{
			if(*(kontrol+1)!='\0')
		{
		ikinci_virgul=kontrol;
		break;
		}
		else ikinci_virgul=p_bir;
	}

}

/* Copy the part from first comma to next comma into 'kopyalancak' */
strncat(kopyalancak, p_bir, (ikinci_virgul-p_bir+1));

/* Search for 'kopyalancak' in the second entry */
if(strloc(trp_girdi2,kopyalancak)) return 1;
}
p_bir++;
}
return 0; }

/* Function for R1 */
void transformation1(char* trp_girdi1, char* trp_girdi2)
{

char* birinci;
char* ikinci;
char* birincip;
char* ikincip;
char *buldu;
char* parantezsiz;
char* virgul;
char* kontrol;
char* parantezli;
char* ikinci_virgul;

virgul=",";
parantezsiz=",-";
parantezli=",-(";

/* Move NOT on left to right */
duzeltme1(trp_girdi1,trp_girdi2);
birinci=trp_girdi1;
ikinci=trp_girdi2;

for(;*birinci;birinci++) 
{
	buldu=strloc(birinci,parantezsiz);
	if(buldu && *(buldu+2)!='(') 
	{ 	/* Locate the next comma */
		for(kontrol=buldu+1;*kontrol;kontrol++)
			if(*kontrol==',') 
			{ 
			ikinci_virgul=kontrol; 
			break;
			}
		
		strncat(ikinci,(buldu+2),(ikinci_virgul-buldu-1)); 
		if(*(kontrol+1)!='\0') 
		{	
			for(birincip=buldu,ikincip=ikinci_virgul; *ikincip ; ikincip++,birincip++)
			{ 
			*birincip=*ikincip; 
			*ikincip='\0';
			} 
		} else *(buldu+1)='\0';

birinci=buldu+1;
}
else;
}

/* Move NOT on right to left */
birinci=trp_girdi1;
ikinci=trp_girdi2;
for(;*birinci;birinci++) 
{
	buldu=strloc(birinci,parantezli);
	if(buldu) 
	{ 	/* Locate the next comma */
		for(kontrol=buldu+1;*kontrol;kontrol++)
		if(*kontrol==',') 
			{ 
			ikinci_virgul=kontrol; 
			break;
			}
		strncat(ikinci,(buldu+2),(ikinci_virgul-buldu-2)); 
		if(*(kontrol+1)!='\0') 
			{	
			for(birincip=buldu,ikincip=ikinci_virgul; *ikincip ; ikincip++,birincip++)
			{ 
			*birincip=*ikincip; 
			*ikincip='\0';
			} 
		} else *(buldu+1)='\0';

birinci=buldu+1;
}
else;
}
}

/* Function for R7 */
/* Termination 2  */

int termination7(char* trp_girdi1, char* trp_girdi2)
{
int result1,result2; 
char* birincip;
char* ikincip;
char* birincip2;
char* ikincip2;

birincip=trp_girdi1;
ikincip=trp_girdi2;
birincip2=trp_girdi1;
ikincip2=trp_girdi2;

/* Check for if there are any connectives - String 1*/
result1=1; result2=1;
while(*trp_girdi1)
{
	if(!(*trp_girdi1=='&' || *trp_girdi1=='|' || *trp_girdi1=='>')) 
	result1*=1; 
	else 
	result1*=0; 
trp_girdi1++;
}

/* If there are no connectives, remove parantheses */
if(result1==1) 
	{
	for(;*birincip;birincip++) if(*birincip==')' || *birincip=='(') 
	*birincip=',';
	}
/* Check for if there are any connectives - String 2*/	
while(*trp_girdi2)
{
	if(!(*trp_girdi2=='&' || *trp_girdi2=='|' || *trp_girdi2=='>')) 
	result2*=1; 
	else 
	result2*=0; 
trp_girdi2++;
}

/* If there are no connectives, remove parantheses */
if(result2==1) 
	{
	for(;*ikincip;ikincip++) if(*ikincip==')' || *ikincip=='(') 
	*ikincip=',';
	}

/* Corrections */
duzeltme1(birincip2,ikincip2);

/*Return the value */
return result1*result2; 
}

/*Function for R3*/
int transformation3(char* trp_girdi1,char* trp_girdi2)
{
int my_func(char* girdi1, char* girdi2);
char *bir_bas;
char *p_bir;
char *ilk_virgul;
char *ikinci_virgul;
char *kontrol;
char *virgul;
char *bolunen1;
char *bolunen2;
char *bolunen12;
char *bolunen11;

virgul=",";
bir_bas=trp_girdi1;
p_bir=bir_bas;

bolunen1=calloc(200,sizeof(char));
bolunen2=calloc(200,sizeof(char));

bolunen11=calloc(200,sizeof(char));
bolunen12=calloc(200,sizeof(char));
my_strcopy(bolunen11,trp_girdi2);
my_strcopy(bolunen12,trp_girdi2);


while(*p_bir)
{
	if(*p_bir=='|')
	{
	/* Locate the previous comma */
	for(kontrol=p_bir;kontrol>=bir_bas;kontrol--)
		if(*kontrol==',' || kontrol==bir_bas ) 
		{ 
		ilk_virgul=kontrol; 
		break;
		}

	/* Locate the next comma */
	for(kontrol=p_bir;;kontrol++)
	if(*kontrol==',' || *kontrol=='\0' ) 
	{ 
	ikinci_virgul=kontrol; 
	break;
	}
	/* Create the divided part I */
	strncat(bolunen1, bir_bas,(ilk_virgul-bir_bas)); 
	strcat(bolunen1, virgul); 
	strncat(bolunen1,ilk_virgul+2,(p_bir-ilk_virgul-2)); 
	strcat(bolunen1,ikinci_virgul);

	/* Create the divided part II */
	strncat(bolunen2, bir_bas,(ilk_virgul-bir_bas)); 
	strcat(bolunen2, virgul); strncat(bolunen2,p_bir+1,(ikinci_virgul-p_bir-2)); 
	strcat(bolunen2,ikinci_virgul);

/* Control for divided parts */
/*
printf("bolunen1: %s\n", bolunen1);
printf("bolunen2: %s\n", bolunen2);
*/

if(	(my_func(bolunen1,bolunen11) == 2 || my_func(bolunen1,bolunen11) == 1 )
 	&& 
	( my_func(bolunen2,bolunen12) == 2 || my_func(bolunen2,bolunen12) == 1) ) 
	{
	
	return 1;
	} 
else 
{
	return 0;
}

break;
}
p_bir++;
}
return 0;}

/* Function for R4 */
int transformation4(char* trp_girdi1,char* trp_girdi2)
{

int my_func(char* girdi1, char* girdi2);
char *bir_bas;
char *p_bir;
char *ilk_virgul;
char *ikinci_virgul;
char *kontrol;
char *virgul;
char *bolunen1;
char *bolunen2;
char *bolunen12;
char *bolunen11;

virgul=",";
bir_bas=trp_girdi2;
p_bir=bir_bas;

bolunen1=calloc(200,sizeof(char));
bolunen2=calloc(200,sizeof(char));

bolunen11=calloc(200,sizeof(char));
bolunen12=calloc(200,sizeof(char));
my_strcopy(bolunen11,trp_girdi1);
my_strcopy(bolunen12,trp_girdi1);


while(*p_bir)
{
	if(*p_bir=='&')
	{
	/* Locate the previous comma */
	for(kontrol=p_bir;kontrol>=bir_bas;kontrol--)
		if(*kontrol==',' || kontrol==bir_bas ) 
		{
		ilk_virgul=kontrol; 
		break;
		}


	/*Locate the next comma */
	for(kontrol=p_bir;;kontrol++)
	if(*kontrol==',' || *kontrol=='\0' ) 
	{
	ikinci_virgul=kontrol; 
	break;
	}
	
	/* Create the divided part I */
	strncat(bolunen1, bir_bas,(ilk_virgul-bir_bas)); 
	strcat(bolunen1, virgul); strncat(bolunen1,ilk_virgul+2,(p_bir-ilk_virgul-2)); 
	strcat(bolunen1,ikinci_virgul);

	/* Create the divided part II */
	
	strncat(bolunen2, bir_bas,(ilk_virgul-bir_bas)); 
	strcat(bolunen2, virgul); strncat(bolunen2,p_bir+1,(ikinci_virgul-p_bir-2)); 
	strcat(bolunen2,ikinci_virgul);

/* Control for the divided parts */
/*
printf("bolunen1: %s\n", bolunen1);
printf("bolunen2: %s\n", bolunen2);
*/

if(  	(my_func(bolunen11,bolunen1) == 2 || my_func(bolunen11,bolunen1) == 1 )
	 && 
	(my_func(bolunen12,bolunen2) == 2 || my_func(bolunen12,bolunen2) == 1) ) 

{
	
	return 1;
} 
else 
{
	
	return 0;
}

break;
}
p_bir++;
}
return 0;}

/* General function for algorithm */
int my_func(char* girdi1, char* girdi2)
{

int don;
don=1;

while(don)
{
	transformation1(girdi2,girdi1);
	duzeltme1(girdi1,girdi2);
	transformation1(girdi1,girdi2);
	duzeltme1(girdi1,girdi2);
	transformation2(girdi1,girdi2);
	duzeltme1(girdi1,girdi2);
	transformation5(girdi1);
	duzeltme1(girdi1,girdi2);
	transformation5(girdi2);
	duzeltme1(girdi1,girdi2);
	
	/* Termination conditions and recursive part */
	if(termination6(girdi1,girdi2)==0 && termination7(girdi1,girdi2)==1) 
	{
		don=0; 
		return 0;
	}

	if(termination6(girdi1,girdi2)==1)
	{
		don=0; 
		return 1; 
	}

	if(termination6(girdi1,girdi2)==0 && termination7(girdi1,girdi2)==0) 
	{ 
		if(transformation3(girdi1,girdi2)==1)
		{
		return 2;
		} 
		
		if(transformation3(girdi1,girdi2)==0 || transformation4(girdi1,girdi2)==0) 
		{
		return 3;
		}

	}

}
return 100;
	
}

/* End of code */
