#include<stdio.h>
#include<string.h>
int GetWordNumber(char string[]);   //���㵥������
int GetCharNumber(char string[]);   //�����ַ�����
int main(int argc ,char *argv[])
{
	char buff[256];
	char string[10000] = "\0";
	FILE *fp = NULL;
	int sum = 0;       //���ս��
	fp = fopen(argv[2],"r");
	//fp = fopen("test.txt","r");
	if(fp == NULL)
	{
		printf("�ļ���ȡʧ��\n");
		return -1;
	}
	while(!feof(fp))
	{
		if(fgets(buff,255,fp) != NULL)
		{ //scanf�����ո�ͻ�Ͽ���gets���ȡ�ո��������оͽ���
			strcat(string,buff);
		}
	} 
	puts(string);
	if(argc != 3)
	{
		printf("arguments error!\n");
	}
	else
	{
		if(strcmp(argv[1],"-v") == 0)
		{
			sum = GetWordNumber(buff);
			printf("�������� %d\n",sum);
		}
		else if(strcmp(argv[1],"-c") == 0)
		{
			sum = GetCharNumber(buff);
			printf("�ַ����� %d\n",sum);
		}
	}
}
int GetWordNumber(char string[])
{
	int i, in_word, word_num;
    word_num = 0;                // ��ʼ�����ʸ���Ϊ0
    in_word = 0;                 // ���λ������Ƿ��ڵ�����
    for (i = 0; string[i]; i++) 
    {
        if (string[i] == ' ') 
        { // ��⵽�ո�
            	in_word = 0;        // ���ñ��λΪ���ڵ�����
        } 
        else if (in_word == 0) 
        { // �ڵ�����
            	word_num++;              // ͳ�Ƶ��ʸ���
            	in_word = 1;          // ���ñ��λΪ�ڵ�����
		}
	}
    return word_num;
}
int GetCharNumber(char string[])
{
	int sum = 0;
	int i ;
	for(i = 0;string[i] != '\0'; i++)
	{//�򵥴ֱ���������
		if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') )
		{
			sum ++;
		}
	}
	return sum ;
}
 
