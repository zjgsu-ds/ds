*****************
第三章 堆栈和队列
*****************

课件
====

* :download:`栈 <chap3_stack.ppt>`
* :download:`队列 <chap3_queue.ppt>`

作业
=====

具体见 `ACM竞赛平台 <http://acm.zjgsu.edu.cn/JudgeOnline/contest.php?cid=1596>`_

作业参考答案
============


`问题 A: 括号匹配(栈和队列) <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1596&pid=0>`_
----------------------------------------------------------------------------------------------

:download:`代码下载 <chap3_A.c>`

.. code-block:: c

    /* 读取字符串 */
    gets(str);

    /* 初始化栈 */
    InitStack(&s);

    len = strlen(str);
    for (i = 0; i < len; i++) {
        curr = str[i];

        if (IsOpenChar(curr)) {          /* 如果当前是左括弧, 压栈 */
            Push(&s, curr);
        } else if (IsCloseChar(curr)) {  /* 如果是右括弧 */
            if (Empty(&s)) {             /* 栈为空, 则没有匹配的左括弧, 出错 */
                printf("NO\n");
                return 0;
            }

            prev = Pop(&s);

            if (!Matched(prev, curr)) { /* 左括弧与当前右括弧的类型不一致, 出错 */
                printf("NO\n");
                return 0;
            }
        }
    }

    if (Empty(&s))
        printf("YES\n");
    else /* 如果栈不为空, 则有左括弧没有匹配, 出错 */
        printf("NO\n");


`问题 B: 翻转句子中单词的顺序（栈和队列） <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1596&pid=1>`_
-------------------------------------------------------------------------------------------------------------

:download:`代码下载 <chap3_B.c>`

.. code-block:: c

    // 读取字符串
    while (gets(str)) {
        len = strlen(str);

        str[0] = ' ';
        str[len-1] = '\0'; /* 忽略最后一个双引号 */

        // 初始化栈容器
        InitStack(&s);

        for (i = 0; i < len; i++) {
            if (str[i] == ' ') {
                str[i] = '\0';
                Push(&s, str + i + 1);
            }
        }

        putchar('"');
        while (s.top != 0) {
            printf("%s", Pop(&s));
            if (s.top > 0)
                putchar(' ');
        }
        putchar('"');
        putchar('\n');
    }


`问题 C: Ackerman 函数(栈和队列)  <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1596&pid=2>`_
-----------------------------------------------------------------------------------------------------

:download:`代码下载 <chap3_C.c>`

.. code-block:: c

    int akm(int m, int n)
    {
        if (m == 0)
            return n + 1;
        else if (n == 0)
            return akm(m-1, 1);
        else
            return akm(m-1, akm(m, n-1));
    }

    int main()
    {
        int m, n;

        scanf("%d%d", &m, &n);

        printf("%d\n", akm(m,n));

        return 0;
    }


`问题 D: 约瑟夫环（栈和队列） <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1596&pid=3>`_
-------------------------------------------------------------------------------------------------

:download:`代码下载 <chap3_D.c>`

.. code-block:: c

    /* Kick out one person, return new start index */
    int kickout(struct data_container *s, int start, int m)
    {
        int i;

        for (i = 1; i < m; i++, start = (start+1) % s->n)
            ;

        del(s, start + 1);

        return start % s->n;
    }

    int main()
    {
        struct data_container s;
        int i, m, n;

        init(&s);

        scanf("%d%d", &n, &m);

        /* 填充数组 */
        for (i = 1; i <= n; i++)
            insert(&s, i, i);

        i = 0;
        while (s.n > 1) {
            i = kickout(&s, i, m);
        }

        printf("%d\n", s.data[0]);

        return 0;
    }



`问题 E: 不同出栈情况(栈和队列) <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1596&pid=4>`_
---------------------------------------------------------------------------------------------------

:download:`代码下载 <chap3_E.c>`

.. code-block:: c

    void enum_stack(struct stack_container data, struct stack_container stack, struct stack_container result)
    {
        if (Empty(&data) && Empty(&stack)) {
            print_stack(&result);
            return;
        } else {
            if (!Empty(&stack)) {
                struct stack_container new_stack = stack;
                struct stack_container new_result = result;
                Push(&new_result, Pop(&new_stack));
                enum_stack(data, new_stack, new_result);
            }

            if (!Empty(&data)) {
                struct stack_container new_data = data;
                struct stack_container new_stack = stack;
                Push(&new_stack, Pop(&new_data));
                enum_stack(new_data, new_stack, result);
            }
        }
    }

`问题 F: 行编辑程序（栈和队列） <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1596&pid=5>`_
---------------------------------------------------------------------------------------------------

:download:`代码下载 <chap3_F.c>`

.. code-block:: c

    InitStack(&s);

    gets(str);
    n = strlen(str);

    for (i = 0; i < n; i++) {
        if (str[i] == '#')
            Pop(&s);
        else if (str[i] == '@')
            Clear(&s);
        else
            Push(&s, str[i]);
    }

    for (i = 0; i < s.top; i++)
        putchar(s.data[i]);

    putchar('\n');


可视化演示
==========

* `堆栈(数组实现) <http://www.cs.usfca.edu/~galles/visualization/StackArray.html>`_
* `堆栈(链表实现) <http://www.cs.usfca.edu/~galles/visualization/StackLL.html>`_
* `队列(数组实现) <http://www.cs.usfca.edu/~galles/visualization/QueueArray.html>`_
* `队列(链表实现) <http://www.cs.usfca.edu/~galles/visualization/QueueLL.html>`_
* `递归求阶乘 <http://www.cs.usfca.edu/~galles/visualization/RecFact.html>`_
* `递归反转字符串 <http://www.cs.usfca.edu/~galles/visualization/RecReverse.html>`_
* `递归求N皇后问题 <http://www.cs.usfca.edu/~galles/visualization/RecQueens.html>`_

代码下载
========

栈
--

* :download:`顺序表实现 <stack.c>`
* :download:`链表实现 <stack_list.c>`
* :download:`递归函数 <recursive_function.c>`
* :download:`汉诺塔 <hanoi.c>`

队列
----

* :download:`顺序表实现 <queue.c>`
* :download:`循环队列 <cycle_queue.c>`
* :download:`循环队列(带溢出判断) <cycle_queue2.c>`
* :download:`杨辉三角 <yangHui_triangle.c>`
