#include <stdio.h>
#include<time.h>
#include <stdlib.h>
int ee = 0;
typedef struct gg
{
	int a;//��
	int b;//��
	int c;//����
	int **seem_1;//�����ڳ�ʼ��
	int **seem_2;//�����û�����֮�����ʾ
}Game;
void answer(Game *tab);//�𰸺���
void eye(Game* tab);//��ʾ����
int ** space(int n, int m);//����ɨ�׿ռ�ĺ���
void show(Game *tab, int e, int f);//��ʾ��Χ�ж����׵ĺ���
void nn(Game *tab, int **n, int er, int ar, int wr);//���׺���
void tozero(int **n, int x, int y);
void yer(Game*tab);//�û������������
void menu(Game*tab);//��ʾ����
void release(Game *tab, int oo);//�ͷ�����ռ�ĺ���
int show_rr(Game *tab, int e, int f);//��ʾһ����Χ�ж��ٸ���
int main()
{
	Game tab;
	srand(time(NULL));
	menu(&tab);
	return 0;
}
void menu(Game *tab)//��ʾ����
{
	printf("�밴����ʾ������Ϸ\n");
	printf("���������������ɨ��(n*m)\n");
	printf("������n��m\n");
	scanf("%d%d", &tab->a, &tab->b);
	tab->seem_1 = space(tab->a, tab->b);
	tab->seem_2 = space(tab->a, tab->b);
	tozero(tab->seem_1, tab->a, tab->b);
	tozero(tab->seem_2, tab->a, tab->b);
	printf("�������׵�����:\n");
	scanf("%d", &tab->c);
	nn(tab, tab->seem_1, tab->a, tab->b, tab->c);
	answer(tab);
	printf("\n");
	printf("\t\t\t\t\t\t\t��Ϸ��ʼ\n");
    printf("\n");
	eye(tab);
	while (1)
	{
		yer(tab);
	}

}
int ** space(int n, int m)//����ɨ�׿ռ�ĺ���
{
	int **p;
	int i = 0;
	p = (int **)malloc(n * sizeof(int));
	for (i = 0; i<n; i++)
	{
		p[i] = (int *)malloc(m * sizeof(int));
	}
	return p;
}
void answer(Game *tab)//�𰸺���
{
	for (int i = 0; i<tab->a; i++)
	{
		for (int j = 0; j<tab->b; j++)
		{
			printf("|");
			if (tab->seem_1[i][j] == 1)
				printf("**");
			else
				printf("__");
		}
		printf("\n");
	}
}
void tozero(int **n, int x, int y)// ����
{
	for (int i = 0; i<x; i++)
		for (int j = 0; j<y; j++)
		{
			n[i][j] = 0;
		}
}
void nn(Game *tab, int **n, int er, int ar, int wr)//���׺���
{
	for (int i = 0; i<wr;)
	{
		int x = rand() % (er - 1) + 1;
		int y = rand() % (ar - 1) + 1;
		n[x][y] = 1;
		i++;
		int out = 0;
		for (int j = 0; j<tab->a; j++)
		{
			for (int t = 0; t<tab->b; t++)
			{
				if (n[j][t] == 1)
					out++;
			}
		}
		if (out != i)
			i = out;
	}
}
void eye(Game *tab)
{
	int i, j;
	for (i = 0; i<tab->a; i++)
	{
		for (j = 0; j<tab->b; j++)
		{
			printf("|");
			switch (tab->seem_2[i][j])
			{
			case 0://��
				printf("**");
				break;
			case 1://��ʾ��Χ�ж�����
				printf("%2d", show_rr(tab, i, j));
				break;
			case 2:
				printf("__");
				break;
			case 3:
				printf("P ");
				break;
			case 4:
				printf("? ");
				break;
			}
		}
		printf("|\n");
	}

}
void yer(Game *tab)//�û������������,����seem_2������
{
	char ae;
	int ge,fe;
	printf("���������꣨��,�У�\n");
	do{
        scanf("%d%d", &ge, &fe);//��ȡ�û������ѡ��(nΪ���,yΪ���)
	    getchar();
	    if(ge>0||fe>0||(ge-1)<=tab->a||(fe-1)<=tab->a)
            printf("�������,����������:\n");
        else
            break;
	  }while(1);
	int te=ge-1;
	int ie=fe-1;
	printf("����nΪ�㿪������yΪ���\n");
	scanf("%c", &ae);
	if (ae == 'n')
	{
	    if(tab->seem_1[te][ie]==1)
        {
            printf("��Ϸ������������\n");
            release(tab, tab->a);
            exit(0);
        }
		show(tab,te,ie);
	}
	else if (ae == 'y')
	{
		if (tab->seem_2[te][ie] == 3)
		{
			tab->seem_2[te][ie] = 4;
			if (tab->seem_1[te][ie] == 1)
				ee--;
		}
		else if (tab->seem_2[te][ie] == 4)
			tab->seem_2[te][ie] = 3;
		else
		{
			tab->seem_2[te][ie] = 3;
			if (tab->seem_1[te][ie] == 1)
				ee++;
			if (ee == tab->c)
			{
				release(tab, tab->a);
				printf("��Ӯ�ˣ�\n");
				exit(0);
			}
		}
	}
	eye(tab);
}
void show(Game *tab, int e, int f)//��ʾһ����Χ8���ж����׵ĺ���
{
			if (e<0 || f<0)
                return;
            if (e>((tab->a)-1)||f>((tab->b)-1))
                return;
            if ((tab->seem_2[e][f] == 0 || tab->seem_2[e][f] == 4 ) && tab->seem_1[e][f] == 0)
         {
            if(show_rr(tab,e,f)>0)//##################################################################0�����ף�1��ʾ�׵ĸ���
                tab->seem_2[e][f]=1;
			else
			{
                tab->seem_2[e][f] = 2;
                show(tab,e-1,f-1);
                show(tab,e,f-1);
                show(tab,e-1,f+1);
                show(tab,e+1,f-1);
                show(tab,e-1,f);
                show(tab,e+1,f+1);
                show(tab,e,f+1);
                show(tab,e+1,f);
            }
        }
	return;
}
void release(Game *tab, int oo)//�ͷ�����ռ�ĺ���
{
	int **n = tab->seem_1;
	int **v = tab->seem_2;
	for (int i = 0; i<oo; i++)
	{
		free(n[i]);
		free(v[i]);
	}
	free(n);
	free(v);
}
int show_rr(Game *tab, int e, int f)//��ʾһ����Χ�ж��ٸ���
{
    int i, j;
	int count = 0;
	for (i = e - 1; i <= e + 1; i++)
		for (j = f - 1; j <= f + 1; j++)
		{
			if (i<0 || j<0)
				continue;
            else if (i>((tab->a)-1)||j>((tab->b)-1))
                continue;
            else if (i == e && j == f)
			{
				continue;
			}
			else if (tab->seem_1[i][j]==1)
				count++;//��������
		}
	return count;

}


