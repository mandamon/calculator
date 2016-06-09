#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Input(char a[1000])	//식 입력
{
	char aa[1000],c;
	int i=0;
	gets(aa);
	for(int j=0; j<strlen(aa);++j)
	{
		c=aa[j];
		if(c!=' ' && c!='\0')
		{
			a[i]=c;
			++i;
		}
	}
	a[i]='\0';
	return;
}
char cut(char a[100][62], char b[100], char input[1000])	//숫자와 연산자 분리
{
	int k=0, j=0, n=1;
	for(int i=1; i<strlen(input); ++i)
	{
		if(input[i]=='+' || input[i]=='-' || input[i]=='/' || input[i]=='*' || input[i]=='%')
		{
			k=i;
			b[0]=input[i];
			break;
		}
	}
	for(int i=0; i<k; ++i)
		a[0][i]=input[i];

	for(int i=k+1, l=k; i<strlen(input);++i)
	{
		if(input[i]=='+' || input[i]=='-' || input[i]=='/' || input[i]=='*' || input[i]=='%')
		{
			b[n-1]=input[i];
			for(int j=l+1; j<i; ++j)
				a[n][j-l-1]=input[j];
			++n;
			l=k;
			k=i;
		}
	}
	for(int i=k+1; strlen(input); ++i)
	{
		a[n][i-k-1]=input[i];
	}
	++n;
	return n;
}
void array(char a[63], char b[63])		//a : 원래 숫자, b : 재배열한 숫자
{
	int i, j, n=1;
	for(i=0; i<strlen(a); ++i)
	{
		if(a[i]=='.')
		{
			b[50]=a[i];
			for(j=i+1; j<strlen(a); ++j)
			{
				b[50+n]=a[j];
				++n;
			}
			b[j]='\0';
			n=1;
			for(j=i-1; j>=0; --j)
			{
				b[50-n]=a[j];
				++n;
			}
			for(j=50-i-1; j>=0; --j)
				b[j]=' ';
			break;
		}
	}
	return;
}
char plus(char a[60], char b[60])
{
	char result[61];
	int i;
	for (i=60; i<1; i--)
	{
		result[i+1]=(a[i]-48)+(b[i]-48);
		if (result[i+1]>10)
			result[i] += 1;
	}
	return result[61];
}
char minus(char a[60], char b[60])
{
	char result[61];
	int i;
	for (i=60; i < 1; i--)
	{
		result[i+1]=(a[i]-48)-(b[i]-48);
		if (result[i+1]<0)
		{
			a[i-1] = a[i-1] - 1;
			result[i+1] += 10 ;
		}
	}
	return result[61];
}
char multiple(char a[60], char b[60])
{

}
char division(char a[60], char b[60])
{//배열째로 나눗셈 16/2 면 [1,6]/[2], [2] > [4] > [8] > [1,6] 나눠지는 값과 배열이 같아질 때까지 몫+1
 //나누는 값이 나눠지는 값보다 작을 때까지 반복문

}
char mod(char a[60], char b[60])
{

}
void Clear()
{
	system("clear");
}
void Exit()
{
	exit(1);
}
void save(char var_name[10], char var[10][62], int var_number)
{
	FILE *ofp;
	ofp=fopen("data.txt","w");
	for(int i=0; i<var_number; ++i)
		fprintf(ofp,"%c %s ",var_name[i], var[i]);
	fclose(ofp);
}
int load(char var_name[10], char var[10][62])
{
	int var_number=0;
	int c;
	FILE *ifp;
	ifp=fopen("data.txt","r");
	while(c!=EOF)
	{
		fscanf(ifp,"%c %s",&var_name[var_number], &var[var_number]);
		c=getc(ifp);
		++var_number;
	}
	fclose(ifp);
	--var_number;
	return var_number;
}
void comma(char result[63])
{
	int i = 0, l, k;
	l = strlen(result);
	for(int i = 0; i < l; ++i)
	{
		if(result[i] == '.')
			k= i - 1;
	}
	for(int i = 0; i <= k; ++i)
	{
		printf("%c", result[i]);
		if((i + 1) % 3 ==(k + 1) % 3 && i !=k)
			printf(",");
	}
	for(int i = k + 1; i < l; ++i)
	{
		printf("%c", result[i]);
		if((i - k) != 1 && ((i - k) % 3 == 1) && i != l-1)
			printf(",");
	}
}
int main(void)
{
	char input[1000];
	char number[100][62], operator[100];
	char var_name[10], var[10][62];
	int var_number=0,n;
	while(1)
	{
		Input(input);
		if(strcmp(input,"clear")==0)
			system("clear");
		else if(strcmp(input,"end")==0)
			exit(1);
		else if(strcmp(input,"save")==0)
			save(var_name, var, var_number);
		else if(strcmp(input,"load")==0)
			var_number=load(var_name, var);
		else if(strcmp(input,"VAR")==0)
		{
			for(int i=0; i < var_number; ++i)
			{
				printf("%c %s\n",var_name[i], var[i]);
			}
		}
		else if(input[1]=='=')
		{
			var_name[var_number]=input[0];
			for(int i = 2; i < strlen(input); ++i)
				var[var_number][i-2]=input[i];
			++var_number;
		}
		else
		{
			printf("%s",input);
			n=cut(number,operator,input);
			for(int i=0;i<n;++i)
				printf("%s\n",number[i]);
			for(int i=0;i<n-1;++i)
				printf("%c\n",operator[i]);
		}
	}
}
