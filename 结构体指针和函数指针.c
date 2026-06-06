#include <stdio.h>
#include <stdlib.h>

typedef struct student{
        char *name;
        int age;
        void (*good_work)(void);//函数指针
        struct student *classmate;
}student, *pstudent;      //int    int*

typedef struct lcd_operation{
        int type;
        void (*draw_logo)(void);
}lcd_operation,*p_lcd_operation;

static void play_ball(void)
{
        printf("playing ball\n");
}

static void sing_song(void)
{
        printf("singing\n");
}

void draw_logo_lcdb(void)
{
        printf("display logo on lcd b\n");
}

void draw_logo_lcda(void)
{
        printf("display logo on lcd a\n");
}
int get_lcd_type()
{
        return 0;
}

 p_lcd_operation get_lcd(void)
 {
        int type=get_lcd_type();
        return &(xxx_com_lcds[type]);
 }

int main()
{
        /*student ss[2]={{"zhangsan",10,play_ball,NULL},{"lili",10,sing_song,NULL}};

        for(int i=0;i<2;i++)
        {
                ss[i].good_work();
        }*/
        p_lcd_operation lcd;
        lcd=get_lcd();
        lcd_operation xxx_com_lcds[2]={{0,draw_logo_lcda},{1,draw_logo_lcdb}};

       p_lcd_operation get_lcd(void);

        return 0;
}




/*int main()
{
        student ss[2]={{"zhangsan",10,NULL},{"lili",10,NULL}};

        for(int i=0;i<2;i++)
        {
                if(strcmp(ss[i].name,"zhangsan")==0)
                {
                        play_ball();
                }
                else if(strcmp(ss[i].name,"lili")==0)
                {
                        sing_song();
                }
        }
        return 0;
}*/

