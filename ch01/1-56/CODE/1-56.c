 #define CHAR /* �ַ��� */
 #include<stdio.h> /* EOF(=^Z��F6),NULL */
 #include<math.h> /* floor(),ceil(),abs() */
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
 #ifdef CHAR
   typedef char TElemType;
   TElemType Nil=' '; /* �ַ����Կո��Ϊ�� */
 #endif
 #ifdef INT
   typedef int TElemType;
   TElemType Nil=0; /* ������0Ϊ�� */
 #endif
 typedef struct BiTNode
 {
   TElemType data;
   struct BiTNode *lchild,*rchild; /* ���Һ���ָ�� */
 }BiTNode,*BiTree;
 Status InitBiTree(BiTree *T)
 { /* �������: ����ն�����T */
   *T=NULL;
   return OK;
 }
 void CreateBiTree(BiTree *T)
 {
   TElemType ch;
 #ifdef CHAR
   scanf("%c",&ch);
 #endif
 #ifdef INT
   scanf("%d",&ch);
 #endif
   if(ch==Nil) /* �� */
     *T=NULL;
   else
   {
     *T=(BiTree)malloc(sizeof(BiTNode));
     if(!*T)
       exit(OVERFLOW);
     (*T)->data=ch; /* ���ɸ���� */
     CreateBiTree(&(*T)->lchild); /* ���������� */
     CreateBiTree(&(*T)->rchild); /* ���������� */
   }
 }

 Status BiTreeEmpty(BiTree T)
 { /* ��ʼ����: ������T���� */
   /* �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE */
   if(T)
     return FALSE;
   else
     return TRUE;
 }

 int BiTreeDepth(BiTree T)
 { /* ��ʼ����: ������T���ڡ��������: ����T����� */
   int i,j;
   if(!T)
     return 0;
   if(T->lchild)
     i=BiTreeDepth(T->lchild);
   else
     i=0;
   if(T->rchild)
     j=BiTreeDepth(T->rchild);
   else
     j=0;
   return i>j?i+1:j+1;
 }

 TElemType Root(BiTree T)
 { /* ��ʼ����: ������T���ڡ��������: ����T�ĸ� */
   if(BiTreeEmpty(T))
     return Nil;
   else
     return T->data;
 }

 void main()
 {
   BiTree T;
   TElemType e1;
   InitBiTree(&T);
   printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   if(e1!=Nil)
 #ifdef CHAR
     printf("�������ĸ�Ϊ: %c\n",e1);
 #endif
 #ifdef INT
     printf("�������ĸ�Ϊ: %d\n",e1);
 #endif
   else
     printf("���գ��޸�\n");
 #ifdef CHAR
   printf("���������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
 #endif
 #ifdef INT
   printf("���������������(��:1 2 0 0 0��ʾ1Ϊ�����,2Ϊ�������Ķ�����)\n");
 #endif
   CreateBiTree(&T);
   printf("������������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   if(e1!=Nil)
 #ifdef CHAR
     printf("�������ĸ�Ϊ: %c\n",e1);
 #endif
 #ifdef INT
     printf("�������ĸ�Ϊ: %d\n",e1);
 #endif
   else
     printf("���գ��޸�\n");
 }

