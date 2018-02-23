//KMP�㷨����Сѭ���ڣ�������һ�����ۣ���Сѭ���ڵĴ�СΪlen-next[len]��
//��Сѭ����ֻ���� len % (len-next[len]) == 0 ʱ�Ŵ���
//KMP�����next[i]���Ա�ʾ��0~i-1�����ǰ׺�ͺ�׺��ͬ���ַ���Ϊnext[i]
#include<stdio.h>
#include<string.h>
#define M 1000
char st1[M];//����
char st2[M];//ģʽ��
int next[M];

void GetNext(char st2[]){
	int len = strlen(st2);
	int i = 0,j = -1;
	next[0] = -1;
	while(i < len){
		if(j == -1||st2[i] == st2[j]){
			i++;
			j++;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
}

int KMP(char st1[],char st2[]){
	int len1 = strlen(st1);
	int len2 = strlen(st2);
	int i = 0, j = 0;
	while(i < len1&&j < len2){
		if(j == -1||st1[i] == st2[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if(j == len2){
		return i - len2;
	}
	return -1;
}
//next�汾2
void GetNext(char st2[]){
	int len = strlen(st2);
	int i = 0,j = -1;
	next[0] = -1;
	while (i<len)
	{
		while (j>=0 && st2[i]!=st2[j]) j=next[j];
		i++;
		j++;
		next[i]=j;
	}
}

int KMP(char st1[],char st2[]){
	int len1 = strlen(st1);
	int len2 = strlen(st2);
	int i = 0, j = 0;
	while (i<len1)
	{
		while (j>=0 && st1[i]!=st2[j]) j=next[j];
		i++;
		j++;
		if (j==len2)
			return i-len2;
	}
	return -1;
}

//nextval�汾
void get_nextval(char const* ptrn, int plen, int* nextval) 
{ 
	int i = 0; 
	nextval[i] = -1; 
	int j = -1; 
	while( i < plen ) 
	{ 
		if( j == -1 || ptrn[i] == ptrn[j] )
		{ 
			++i; 
			++j; 
			if( ptrn[i] != ptrn[j] ) nextval[i] = j;//++i��++j֮���ٴ��ж�ptrn[i]��ptrn[j]�Ĺ�ϵ
			else nextval[i] = nextval[j]; 
		} 
		else j = nextval[j]; 
	} 
} 

int kmp_search(char const* src, int slen, char const* patn, int plen, int const* nextval, int pos) //�˴���֧�ִ�posλ��ʼƥ��
{
	int i = pos; 
	int j = 0; 
	while ( i < slen && j < plen ) 
	{ 
		if( j == -1 || src[i] == patn[j] ) 
		{ 
			++i; 
			++j; 
		} 
		else j = nextval[j]; //��ƥ��ʧ�ܵ�ʱ��ֱ����p[j_next]��s[i]�Ƚϣ���ƥ��ʧЧ����һ��ƥ���λ�� 
	} 
	if( j >= plen ) return i-plen; 
	else return -1; 
} 
