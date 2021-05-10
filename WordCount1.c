#include<stdio.h>
#include<string.h>
int GetWordNumber(char string[]);   //计算单词数量
int GetCharNumber(char string[]);   //计算字符数量
int main(int argc ,char *argv[])
{
	char buff[256];
	char string[10000] = "\0";
	FILE *fp = NULL;
	int sum = 0;       //最终结果
	fp = fopen(argv[2],"r");
	//fp = fopen("test.txt","r");
	if(fp == NULL)
	{
		printf("文件读取失败\n");
		return -1;
	}
	while(!feof(fp))
	{
		if(fgets(buff,255,fp) != NULL)
		{ //scanf遇到空格就会断开，gets会读取空格，遇到换行就结束
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
			printf("单词数： %d\n",sum);
		}
		else if(strcmp(argv[1],"-c") == 0)
		{
			sum = GetCharNumber(buff);
			printf("字符数： %d\n",sum);
		}
	}
}
int GetWordNumber(char string[])
{
	int i, in_word, word_num;
    word_num = 0;                // 初始化单词个数为0
    in_word = 0;                 // 标记位，标记是否在单词内
    for (i = 0; string[i]; i++) 
    {
        if (string[i] == ' ') 
        { // 检测到空格
            	in_word = 0;        // 设置标记位为不在单词内
        } 
        else if (in_word == 0) 
        { // 在单词内
            	word_num++;              // 统计单词个数
            	in_word = 1;          // 设置标记位为在单词内
		}
	}
    return word_num;
}
int GetCharNumber(char string[])
{
	int sum = 0;
	int i ;
	for(i = 0;string[i] != '\0'; i++)
	{//简单粗暴，不解释
		if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') )
		{
			sum ++;
		}
	}
	return sum ;
}
 
