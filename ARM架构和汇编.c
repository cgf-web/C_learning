#include <stdio.h>


/*ARM架构是精简指令集，对于内存，只有读写两个操作，所有的计算都是在CPU内部操作的
        R0寄存器～R15寄存器    读就是LDR  目的，源     LDR  R0,[a]
                                                                                                        LDR   R1,[b]
                                                        加       ADD  R0,R0,R1
                                                写        STR R0，[a]
        四条汇编指令保存在flash上
*/


int g_a=0x12345678;//在内存中     断电时没有    运行时有

int main()
{
        volatile int a=1;
        volatile int b=2;
        a=a+b;
        printf("a=%d\n",a);
        return 0;
}


/*全局变量的初始化：
        1.全局变量（有非零初始值）：保存在flash
                 a.   LDR  R0,[ flash_addr]           STR  R0,[g_a_addr]    效率低
                b.  全局变量集中在一起，放在数据段      将数据段整段整段复制到内存（类似memcpy）
        2.初始值为零，或者没有初始化的全局变量      不会存放在flash中
        这些变量在内存里都放在ZI段，   初始化时  类似memset把ZI段全部清零


        局部变量的初始化
        BL：Branch/Link        LR(R14寄存器)：保存返回地址
                                                调用多个函数时，LR寄存器数据会被覆盖   所以得提前先把LR中的保存的地址存入栈中

        SP寄存器指向一块空闲的内存        栈

        调用main();

       局部变量在哪？
        push  {r2-r4,lr}把r2-r4,lr推入栈中，SP-->SP-16;

        栈的作用

*/